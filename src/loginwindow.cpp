#include "loginwindow.hpp"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget{parent}
{
    //Welcome label
    loginMessage = new QLabel(this);

    rsuLogo = new QLabel(this);

    //Username
    userNameForLogin = new QLabel(this);

    entryForUserName = new QLineEdit(this);
    //Username

    //Password
    passwordForLogin = new QLabel(this);
    entryForPassword = new QLineEdit(this);
    //Password

    //University
    univer = new QLabel(this);
    uni = new QComboBox(this);
    //University

    //Pushbutton - login
    loginButton = new QPushButton(this);
    //Pushbutton - login

    //Pushbutton - signup
    SignupButton = new QPushButton(this);
    //Pushbutton - signup

    //NAME LAYOUT
    UserNameLayout = new QHBoxLayout;
    UserNameLayout->addWidget(userNameForLogin);
    UserNameLayout->addWidget(entryForUserName);

    //NAME LAYOUT
    passwordLayout = new QHBoxLayout;
    passwordLayout->addWidget(passwordForLogin);
    passwordLayout->addWidget(entryForPassword);

    //UNI LAYOUT
    uniLayout = new QHBoxLayout;
    uniLayout->addWidget(univer);
    uniLayout->addWidget(uni);

    //LOGIN AND SIGNUP LAYOUT
    loginORsignup = new QHBoxLayout;
    loginORsignup->addWidget(loginButton);
    loginORsignup->addWidget(SignupButton);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(loginMessage);
    mainLayout->addWidget(rsuLogo);
    mainLayout->addLayout(UserNameLayout);
    mainLayout->addLayout(uniLayout);
    mainLayout->addLayout(passwordLayout);
    mainLayout->addLayout(loginORsignup);
    this->setLayout(mainLayout);
    this->refreshPage();
}

void LoginWindow::reset(){
    entryForUserName->clear();
    uni->clear();
    entryForPassword->clear();
}

void LoginWindow::refreshPage(){
    loginMessage->setText("Welcome to The Course Registration Portal!");
    loginMessage->setFont(QFont("Times", 29));

    rsuLogo->setPixmap(QPixmap(":/rsu_logo128.jpg"));
    rsuLogo->setScaledContents(true);

    userNameForLogin->setText("Username");
    userNameForLogin->setFont(QFont("Times"));

    entryForUserName->setPlaceholderText("Enter your username");
    entryForUserName->setFont(QFont("Times"));

    passwordForLogin->setText("Password");
    passwordForLogin->setFont(QFont("Times"));

    entryForPassword->setPlaceholderText("Enter your password");
    entryForPassword->setEchoMode(QLineEdit::Password);
    entryForPassword->setFont(QFont("Times"));

    univer->setText("University");
    univer->setFont(QFont("Times"));

    uni->addItem("Rivers State University");

    loginButton->setText("Login");
    SignupButton->setText("Sign up");

    disconnect(loginConnection);

    loginConnection = QObject::connect(loginButton, &QPushButton::clicked, [this](){
        QString username = entryForUserName->text();
        QString password = entryForPassword->text();

        if(username.isEmpty() || password.isEmpty()){
            QMessageBox::warning(this, "Error", "Incomplete Credentials");
        }
        else{
            reader_json["user_name"] = username.toStdString();
            reader_json["raw_password"] = password.toStdString();

            //for transferring the json data to the server
            QNetworkAccessManager* clientApp = new QNetworkAccessManager(this);

            std::cout << reader_json.dump() << std::endl;

            //can only transfer raw bytes
            QByteArray data = QByteArray::fromStdString(reader_json.dump());

            //envelope for sending request
            QNetworkRequest request(QUrl(QString("http://%1:%2/login/student").arg(ipAddress, portNumber)));//"http://" + ipAddress + ":" + portNumber + "register"));
            //request type
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

            //object for receiving the server's reply
            QNetworkReply* reply = clientApp->post(request, data);

            //does stuff when the server replies
            QObject::connect(reply, &QNetworkReply::finished, this, [this, reply]{
                //gets connection code
                int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

                //checks if an error was returned and if the status code is equal to 200
                if(reply->error() == QNetworkReply::NoError && (statusCode == 200 || statusCode == 201)){
                    serverResponse = nlohmann::json::parse(reply->readAll().toStdString());
                    std::cout << termcolor::green << "Success: " << serverResponse["message"] << termcolor::reset << std::endl;

                    QMessageBox::information(this, "Success", "Successfully logged in, redirecting page now...");
                    emit account_page();
                }
                else if(reply->error() == QNetworkReply::ConnectionRefusedError){
                    //auto serverResponse = nlohmann::json::parse(reply->readAll().toStdString());
                    std::cout << termcolor::red << "Server Error" << termcolor::reset << std::endl;
                    QMessageBox::warning(this, "Server Error", "Server is down, contact support or wait");
                }
                else{
                    serverResponse = nlohmann::json::parse(reply->readAll().toStdString());
                    std::cerr << termcolor::red << "Message: " << serverResponse["message"]/*"Failed to create an account"*/ << termcolor::reset << std::endl;
                    QMessageBox::warning(this, "Error", QString::fromStdString(serverResponse["message"]));
                }

                reply->deleteLater();
            });
        }
    });

    QObject::disconnect(SignupConnection);

    SignupConnection = QObject::connect(SignupButton, &QPushButton::clicked, [this](){
        QMessageBox::information(this, "Sign Up", "Redirecting to Sign up page");
        emit signup_page();
    });
}
