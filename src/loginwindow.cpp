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

    loginCount = 0;

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

            QPointer<LoginWindow> self(this);

            std::jthread([self](std::stop_token st){
                if(st.stop_requested()) std::exit(0);

                QString Url = QString("http://%1:%2").arg(self->ipAddress, self->portNumber);

                httplib::Client client(Url.toStdString());
                auto response = client.Post("/login/student", self->reader_json.dump(), "application/json");

                if(response){
                    if(response->status == 200){
                        self->loginCount++;
                        self->serverResponse = nlohmann::json::parse(response->body);
                        std::cout << termcolor::green << "Success: " << self->serverResponse["message"] << termcolor::reset << std::endl;
                        QMetaObject::invokeMethod(self, [self, st](){
                            if(st.stop_requested()) std::exit(0);
                            if(self->loginCount == 1){
                                QMessageBox::information(self, "Success", "Successfully logged in, redirecting page now...");
                                emit self->account_page();
                            }
                        }, Qt::QueuedConnection);
                    }
                    else{
                        //self->loginCount++;
                        self->serverResponse = nlohmann::json::parse(response->body);
                        //if(self->loginCount == 1){
                            std::cerr << termcolor::red << "Message: " << self->serverResponse["message"] << termcolor::reset << std::endl;
                            QMetaObject::invokeMethod(self, [self, st](){
                                if(st.stop_requested()) std::exit(0);
                                QMessageBox::warning(self, "Error", QString::fromStdString(self->serverResponse["message"]));
                            }, Qt::QueuedConnection);
                        //}
                    }
                }
                else{
                    std::cout << termcolor::red << "Server Error" << termcolor::reset << std::endl;
                    QMetaObject::invokeMethod(self, [self, st](){
                        if(st.stop_requested()) std::exit(0);
                        QMessageBox::warning(self, "Server Error", "Server is down, contact support or wait");
                    }, Qt::QueuedConnection);
                }

            }).detach();
        }
    });


    signupCount = 0;
    QObject::disconnect(SignupConnection);

    SignupConnection = QObject::connect(SignupButton, &QPushButton::clicked, [this](){
        signupCount++;
        if(signupCount == 1){
            QMessageBox::information(this, "Sign Up", "Redirecting to Sign up page");
            emit signup_page();
        }
    });
}
