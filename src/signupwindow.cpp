#include "signupwindow.hpp"

SignupWindow::SignupWindow(QWidget *parent)
    : QWidget{parent}
{
    //Welcome label
    SigningLabel = new QLabel(this);
    SigningLabel->setText("Create an account and register courses");
    SigningLabel->setFont(QFont("Times", 25));
    //Welcome label

    rsuLogo = new QLabel(this);
    rsuLogo->setPixmap(QPixmap(":/rsu_logo128.jpg"));
    rsuLogo->setScaledContents(true);

    //First name - required
    first_name = new QLabel(this);
    first_name->setText("First name");
    first_name->setFont(QFont("Times"));

    firstNameLE = new QLineEdit(this);
    firstNameLE->setPlaceholderText("Required");
    firstNameLE->setFont(QFont("Times"));
    //First name - required

    //Middle name - optional
    middle_name = new QLabel(this);
    middle_name->setText("Middle name");
    middle_name->setFont(QFont("Times"));

    middleNameLE = new QLineEdit(this);
    middleNameLE->setPlaceholderText("Optional");
    middleNameLE->setFont(QFont("Times"));
    //Middle name - optional

    //last name - required
    last_name = new QLabel(this);
    last_name->setText("Last name");
    last_name->setFont(QFont("Times"));

    lastNameLE = new QLineEdit(this);
    lastNameLE->setPlaceholderText("Required");
    lastNameLE->setFont(QFont("Times"));
    //last name - required

    //Username
    userName = new QLabel(this);
    userName->setText("Username");
    userName->setFont(QFont("Times"));

    un = new QLineEdit(this);
    un->setPlaceholderText("Required");
    un->setFont(QFont("Times"));
    //Username

    //Gender/Sex
    gender = new QLabel(this);
    gender->setText("Select your gender");
    gender->setFont(QFont("Times"));

    gen = new QComboBox(this);
    gen->addItem("Male");
    gen->addItem("Female");
    gen->addItem("Prefer not to say");
    //Gender/Sex

    //Department
    department = new QLabel(this);
    department->setText("Department");
    department->setFont(QFont("Times"));

    dept = new QComboBox(this);
    dept->addItem("Agric Engineering");
    dept->addItem("Chemical Engineering");
    dept->addItem("Computer Engineering");
    dept->addItem("Civil Engineering");
    dept->addItem("Electrical/Electronics Enginering");
    dept->addItem("Marine Engineering");
    dept->addItem("Mechanical Engineering");
    dept->addItem("Petroleum");
    //Department

    //Level
    level = new QLabel(this);
    level->setText("Level");
    level->setFont(QFont("Times"));

    lvl = new QComboBox(this);
    lvl->addItem("100");
    lvl->addItem("200");
    lvl->addItem("300");
    lvl->addItem("400");
    lvl->addItem("500");
    //Level

    //Mat NO
    matricNO = new QLabel(this);
    matricNO->setText("Matriculation Number");
    matricNO->setFont(QFont("Times"));

    mn = new QLineEdit(this);
    mn->setPlaceholderText("Enter the four digits in your MAT. NO.");
    mn->setFont(QFont("Times"));
    //Mat NO

    //University
    univer = new QLabel(this);
    univer->setText("University");
    univer->setFont(QFont("Times"));

    uni = new QComboBox(this);
    uni->addItem("Rivers State University");
    //University

    //Email and Phone No
    email_add = new QLabel(this);
    email_add->setText("Email");
    email_add->setFont(QFont("Times"));

    em = new QLineEdit(this);
    em->setPlaceholderText("Required");
    em->setFont(QFont("Times"));

    phone_no = new QLabel(this);
    phone_no->setText("Phone number");
    phone_no->setFont(QFont("Times"));

    pn = new QLineEdit(this);
    pn->setPlaceholderText("Required");
    pn->setFont(QFont("Times"));
    //Email and Phone No

    //login and sign up
    loginButton = new QPushButton(this);
    loginButton->setText("Already have an account");

    SignupButton = new QPushButton(this);
    SignupButton->setText("Sign up");
    //login and sign up


    //Password
    //first
    password1= new QLabel(this);
    password1->setText("Password");
    password1->setFont(QFont("Times"));

    pass1 = new QLineEdit(this);
    pass1->setPlaceholderText("Enter new password");
    pass1->setEchoMode(QLineEdit::Password);
    pass1->setFont(QFont("Times"));

    //second
    password2= new QLabel(this);
    password2->setText("Re-enter Password");
    password2->setFont(QFont("Times"));

    pass2 = new QLineEdit(this);
    pass2->setPlaceholderText("Enter password again");
    pass2->setEchoMode(QLineEdit::Password);
    pass2->setFont(QFont("Times"));
    //Password

    //PASSWORD LAYOUT
    passwordLayout1 = new QHBoxLayout;
    passwordLayout1->addWidget(password1);
    passwordLayout1->addWidget(pass1);

    passwordLayout2 = new QHBoxLayout;
    passwordLayout2->addWidget(password2);
    passwordLayout2->addWidget(pass2);
    //PASSWORD LAYOUT

    //LOGIN AND SIGNUP LAYOUT
    loginORsignup = new QHBoxLayout;
    loginORsignup->addWidget(loginButton);
    loginORsignup->addWidget(SignupButton);
    //LOGIN AND SIGNUP LAYOUT

    //FIRST NAME LAYOUT
    firstNameLayout = new QHBoxLayout;
    firstNameLayout->addWidget(first_name);
    firstNameLayout->addWidget(firstNameLE);
    //FIRST NAME LAYOUT

    //MIDDLE NAME LAYOUT
    middleNameLayout = new QHBoxLayout;
    middleNameLayout->addWidget(middle_name);
    middleNameLayout->addWidget(middleNameLE);
    //MIDDLE NAME LAYOUT

    //LAST NAME LAYOUT
    lastNameLayout = new QHBoxLayout;
    lastNameLayout->addWidget(last_name);
    lastNameLayout->addWidget(lastNameLE);
    //LAST NAME LAYOUT

    //USERNAME LAYOUT
    userNameLayout = new QHBoxLayout;
    userNameLayout->addWidget(userName);
    userNameLayout->addWidget(un);
    //USERNAME LAYOUT

    //GENDER LAYOUT
    genderLayout = new QHBoxLayout;
    genderLayout->addWidget(gender);
    genderLayout->addWidget(gen);
    //GENDER  LAYOUT

    //DEPARTMENT LAYOUT
    deptLayout = new QHBoxLayout;
    deptLayout->addWidget(department);
    deptLayout->addWidget(dept);
    //DEPARTMENT  LAYOUT

    //UNI LAYOUT
    uniLayout = new QHBoxLayout;
    uniLayout->addWidget(univer);
    uniLayout->addWidget(uni);
    //UNI LAYOUT

    //EMAIL AND PHONE NUMBER
    emailLayout = new QHBoxLayout;
    emailLayout->addWidget(email_add);
    emailLayout->addWidget(em);

    phoneNoLayout = new QHBoxLayout;
    phoneNoLayout->addWidget(phone_no);
    phoneNoLayout->addWidget(pn);
    //EMAIL AND PHONE NUMBER

    //LEVEL LAYOUT
    levelLayout = new QHBoxLayout;
    levelLayout->addWidget(level);
    levelLayout->addWidget(lvl);
    //LEVEL LAYOUT

    //MATRIC NUMBER
    mnLayout = new QHBoxLayout;
    mnLayout->addWidget(matricNO);
    mnLayout->addWidget(mn);
    //MATRIC NUMBER

    //MAIN LAYOUT
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(SigningLabel);
    mainLayout->addWidget(rsuLogo);
    mainLayout->addLayout(firstNameLayout);
    mainLayout->addLayout(middleNameLayout);
    mainLayout->addLayout(lastNameLayout);
    mainLayout->addLayout(userNameLayout);
    mainLayout->addLayout(genderLayout);
    mainLayout->addLayout(uniLayout);
    mainLayout->addLayout(deptLayout);
    mainLayout->addLayout(levelLayout);
    mainLayout->addLayout(mnLayout);
    mainLayout->addLayout(emailLayout);
    mainLayout->addLayout(phoneNoLayout);
    mainLayout->addLayout(passwordLayout1);
    mainLayout->addLayout(passwordLayout2);
    mainLayout->addLayout(loginORsignup);
    this->setLayout(mainLayout);
    //MAIN LAYOUT

    QObject::connect(SignupButton, &QPushButton::clicked, [&](){
        QString f_name = firstNameLE->text();
        QString m_name = middleNameLE->text();
        QString l_name = lastNameLE->text();

        QString user_name = un->text();

        QString gen_v = gen->currentText();
        QString dept_v = dept->currentText();

        int level_v = 0;

        try{
            level_v = /*std::stoi(*/lvl->currentText().toInt();//(//.toStdString());
        }
        catch(const std::exception& error){
            std::cerr << termcolor::red << "Error in converting level to an INT" << termcolor::reset << std::endl;
        }

        QString uni_v = uni->currentText();

        QString mat_no = "";

        mat_no = (level_v == 100)? "DE.2025/": (level_v == 200)? "DE.2024/": (level_v == 300)? "DE.2023/": (level_v == 400)? "DE.2022/": (level_v == 500)? "DE.2021/": "UNKNOWN";
        mat_no += mn->text();

        QString email_v = em->text();
        QString phone_no_v = pn->text();

        auto pnv = this->getInput(pn);
        //if(pnv) std::cout << "Phn No: " << pnv.value() << std::endl;
        auto mnv = this->getInput(mn);
        //if(mnv) std::cout << "Mat No: " << mnv.value() << std::endl;


        QString password_1_v = pass1->text();
        QString password_2_v = pass2->text();

        if(!pnv || !mnv || f_name.isEmpty() || l_name.isEmpty() || user_name.isEmpty() || email_v.isEmpty() || phone_no_v.isEmpty() || password_1_v.isEmpty() || password_2_v.isEmpty() || mat_no.isEmpty()){
            if(f_name.isEmpty() || l_name.isEmpty() || user_name.isEmpty() || email_v.isEmpty() || phone_no_v.isEmpty() || password_1_v.isEmpty() || password_2_v.isEmpty() || mat_no.isEmpty()){
                QMessageBox::warning(this, "Error", "Incomplete Details!");
            }
            else {
                if(!pnv && mnv){
                    QMessageBox::warning(this, "Error", "Invalid phone number!");
                }
                else if(!mnv && pnv){
                    QMessageBox::warning(this, "Error", "Invalid matric number!");
                }
                else if(!pnv && !mnv ){
                    QMessageBox::warning(this, "Error", "Invalid phone and matric number!");
                }
            }
        }
        else if(password_1_v != password_2_v){
            QMessageBox::warning(this, "Error", "Passwords don't match!");
        }
        else{
            json_reader = {
                {"users", {
                    {"user_name", user_name.toStdString()},
                    {"role", "student"}
                }},
                {"student",{
                    {"mat_no", mat_no.toStdString()},
                    {"first_name", f_name.toStdString()},
                    {"middle_name", m_name.toStdString()},
                    {"last_name", l_name.toStdString()},
                    {"sex", gen_v.toStdString()},
                    {"dept", dept_v.toStdString()},
                    {"level", level_v},
                    {"email", email_v.toStdString()},
                    {"phone_no", phone_no_v.toLongLong()},
                    {"user_name", user_name.toStdString()},
                    {"school_id", 100001}
                }},
                {"raw", {
                    {"password", pass1->text().toStdString()}
                }}
            };

            //for transferring the json data to the server
            QNetworkAccessManager* clientApp = new QNetworkAccessManager(this);
            //can only transfer raw bytes
            QByteArray data = QByteArray::fromStdString(json_reader.dump());

            //envelope for sending request
            QNetworkRequest request(QUrl(QString("http://%1:%2/register").arg(ipAddress, portNumber)));//"http://" + ipAddress + ":" + portNumber + "register"));
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
                    auto serverResponse = nlohmann::json::parse(reply->readAll().toStdString());
                    std::cout << termcolor::green << "Success: " << serverResponse["message"] << termcolor::reset << std::endl;

                    QMessageBox::information(this, "Success", "Successfully created account, redirecting page now...");
                    emit account_page();
                }
                else if(reply->error() == QNetworkReply::HostNotFoundError){
                    auto serverResponse = nlohmann::json::parse(reply->readAll().toStdString());
                    std::cout << termcolor::green << "Internet Connection Required" << termcolor::reset << std::endl;
                    QMessageBox::warning(this, "Network Error", "Internet Connection Required");
                }
                else{
                    std::cerr << termcolor::red << "Failed to create an account" << termcolor::reset << std::endl;
                    QMessageBox::warning(this, "Error", "Failed to create account");
                }

                reply->deleteLater();
            });
        }
    });

    QObject::connect(loginButton, &QPushButton::clicked, [&](){
        QMessageBox::information(this, "Sign Up", "Redirecting to Login page");
        emit login_page();
    });
}

void SignupWindow::reset(){
    firstNameLE->clear();
    middleNameLE->clear();
    lastNameLE->clear();

    gen->clear();
    uni->clear();
    dept->clear();
    lvl->clear();
    mn->clear();

    em->clear();
    pn->clear();

    pass1->clear();
    pass2->clear();
}
