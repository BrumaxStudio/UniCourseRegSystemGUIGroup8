#include "signupwindow.hpp"

SignupWindow::SignupWindow(QWidget *parent)
    : QWidget{parent}
{
    //Welcome label
    SigningLabel = new QLabel(this);
    //Welcome label

    rsuLogo = new QLabel(this);
    rsuLogo->setPixmap(QPixmap(":/rsu_logo128.jpg"));
    rsuLogo->setScaledContents(true);

    //First name - required
    first_name = new QLabel(this);
    firstNameLE = new QLineEdit(this);
    //First name - required

    //Middle name - optional
    middle_name = new QLabel(this);
    middleNameLE = new QLineEdit(this);
    //Middle name - optional

    //last name - required
    last_name = new QLabel(this);
    lastNameLE = new QLineEdit(this);
    //last name - required

    //Username
    userName = new QLabel(this);
    un = new QLineEdit(this);
    un->setPlaceholderText("Required");
    un->setFont(QFont("Times"));
    //Username

    //Gender/Sex
    gender = new QLabel(this);
    gen = new QComboBox(this);
    //Gender/Sex

    //Date of Birth
    date_of_birth = new QLabel(this);
    birth = new QDateEdit(QDate::currentDate(), this);
    //Date of Birth

    //Department
    department = new QLabel(this);
    dept = new QComboBox(this);
    //Department

    //Level
    level = new QLabel(this);
    lvl = new QComboBox(this);
    //Level

    //Mat NO
    matricNO = new QLabel(this);
    mn = new QLineEdit(this);
    //Mat NO

    //University
    univer = new QLabel(this);
    uni = new QComboBox(this);
    //University

    //Email and Phone No
    email_add = new QLabel(this);
    em = new QLineEdit(this);
    phone_no = new QLabel(this);
    pn = new QLineEdit(this);
    //Email and Phone No

    //login and sign up
    loginButton = new QPushButton(this);
    SignupButton = new QPushButton(this);
    //login and sign up

    //Password
    //first
    password1= new QLabel(this);
    pass1 = new QLineEdit(this);

    //second
    password2= new QLabel(this);
    pass2 = new QLineEdit(this);
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

    //DATE OF BIRTH LAYOUT
    birth_layout = new QHBoxLayout;
    birth_layout->addWidget(date_of_birth);
    birth_layout->addWidget(birth);
    //DATE OF BIRTH LAYOUT

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
    mainLayout->addLayout(birth_layout);
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


}

void SignupWindow::refreshPage(){
    SigningLabel->setText("Create an account and register courses");
    SigningLabel->setFont(QFont("Times", 25));

    first_name->setText("First name");
    first_name->setFont(QFont("Times"));

    firstNameLE->setPlaceholderText("Required");
    firstNameLE->setFont(QFont("Times"));

    middle_name->setText("Middle name");
    middle_name->setFont(QFont("Times"));

    middleNameLE->setPlaceholderText("Optional");
    middleNameLE->setFont(QFont("Times"));

    last_name->setText("Last name");
    last_name->setFont(QFont("Times"));
    lastNameLE->setPlaceholderText("Required");
    lastNameLE->setFont(QFont("Times"));

    userName->setText("Username");
    userName->setFont(QFont("Times"));

    gender->setText("Select your gender");
    gender->setFont(QFont("Times"));

    gen->addItem("Male");
    gen->addItem("Female");
    gen->addItem("Prefer not to say");

    date_of_birth->setText("Date of Birth");
    date_of_birth->setFont(QFont("Times"));

    birth->setCalendarPopup(true);
    birth->setDisplayFormat("dd-MM-yyyy");

    department->setText("Department");
    department->setFont(QFont("Times"));

    dept->addItem("Agric Engineering");
    dept->addItem("Chemical Engineering");
    dept->addItem("Computer Engineering");
    dept->addItem("Civil Engineering");
    dept->addItem("Electrical/Electronics Engineering");
    dept->addItem("Marine Engineering");
    dept->addItem("Mechanical Engineering");
    dept->addItem("Petroleum");

    level->setText("Level");
    level->setFont(QFont("Times"));

    lvl->addItem("100");
    lvl->addItem("200");
    lvl->addItem("300");
    lvl->addItem("400");
    lvl->addItem("500");

    matricNO->setText("Matriculation Number");
    matricNO->setFont(QFont("Times"));

    mn->setPlaceholderText("Enter the four digits in your MAT. NO.");
    mn->setFont(QFont("Times"));

    univer->setText("University");
    univer->setFont(QFont("Times"));
    uni->addItem("Rivers State University");

    email_add->setText("Email");
    email_add->setFont(QFont("Times"));

    em->setPlaceholderText("Required");
    em->setFont(QFont("Times"));

    phone_no->setText("Phone number");
    phone_no->setFont(QFont("Times"));

    pn->setPlaceholderText("Required");
    pn->setFont(QFont("Times"));

    loginButton->setText("Already have an account");

    SignupButton->setText("Sign up");

    password1->setText("Password");
    password1->setFont(QFont("Times"));

    pass1->setPlaceholderText("Enter new password");
    pass1->setEchoMode(QLineEdit::Password);
    pass1->setFont(QFont("Times"));

    password2->setText("Re-enter Password");
    password2->setFont(QFont("Times"));

    pass2->setPlaceholderText("Enter password again");
    pass2->setEchoMode(QLineEdit::Password);
    pass2->setFont(QFont("Times"));

    signupCount = 0;

    QObject::disconnect(SignupConnection);

    SignupConnection = QObject::connect(SignupButton, &QPushButton::clicked, [this](){
        QString f_name = firstNameLE->text();
        QString m_name = middleNameLE->text();
        QString l_name = lastNameLE->text();

        QString user_name = un->text();

        QString gen_v = gen->currentText();
        QString dob_v = birth->date().toString("yyyy-MM-dd");
        QString dept_v = dept->currentText();

        int level_v = 0;

        try{
            level_v = lvl->currentText().toInt();
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

        auto pnv = this->getInput<long long>(pn);
        if(pnv) std::cout << termcolor::green << "Phn No is valid " << termcolor::reset << std::endl;
        else std::cout << termcolor::red << "Phn No is invalid " << termcolor::reset << std::endl;

        auto mnv = this->getInput<int>(mn);
        if(mnv) std::cout << termcolor::green << "Mat No is valid " << termcolor::reset << std::endl;
        else std::cout << termcolor::red << "Mat No is invalid " << termcolor::reset << std::endl;


        QString password_1_v = pass1->text();
        QString password_2_v = pass2->text();

        if(!emailValidator(email_v) || !phoneNoValidator(phone_no_v) || !matNoValidator(mn->text()) || f_name.isEmpty() || l_name.isEmpty() || user_name.isEmpty() || email_v.isEmpty() || phone_no_v.isEmpty() || password_1_v.isEmpty() || password_2_v.isEmpty() || mat_no.isEmpty()){
            if(f_name.isEmpty() || l_name.isEmpty() || user_name.isEmpty() || email_v.isEmpty() || phone_no_v.isEmpty() || password_1_v.isEmpty() || password_2_v.isEmpty() || mat_no.isEmpty()){
                QMessageBox::warning(this, "Error", "Incomplete Details!");
            }
            else if(!emailValidator(email_v) || !phoneNoValidator(phone_no_v) || !matNoValidator(mn->text())) {
                if(!phoneNoValidator(phone_no_v) && emailValidator(email_v) && matNoValidator(mn->text())){
                    QMessageBox::warning(this, "Error", "Invalid phone number!");
                }
                else if(!matNoValidator(mn->text()) && emailValidator(email_v) && phoneNoValidator(phone_no_v)){
                    QMessageBox::warning(this, "Error", "Invalid matric number!");
                }
                else if(!emailValidator(email_v) && matNoValidator(mn->text()) && phoneNoValidator(phone_no_v)){
                    QMessageBox::warning(this, "Error", "Invalid email address!");
                }
                else{
                    QMessageBox::warning(this, "Error", "Invalid phone and/or matric number and/or email address!");
                }
            }
        }
        else if(password_1_v != password_2_v){
            QMessageBox::warning(this, "Error", "Passwords don't match!");
        }
        else{
            reader_json = {
                {"users", {
                              {"user_name", user_name.toStdString()},
                              {"role", "student"}
                          }},
                {"student",{
                                {"mat_no", mat_no.toStdString()},
                                {"first_name", f_name.toStdString()},
                                {"middle_name", m_name.toStdString()},
                                {"last_name", l_name.toStdString()},
                                {"gender", gen_v.toStdString()},
                                {"date_of_birth", dob_v.toStdString()},
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

            QPointer<SignupWindow> self(this);

            std::jthread([self](std::stop_token st){
                if(st.stop_requested()) std::exit(0);

                QString Url = QString("http://%1:%2").arg(self->ipAddress, self->portNumber);

                httplib::Client client(Url.toStdString());
                auto response = client.Post("/register", self->reader_json.dump(), "application/json");

                if(response){
                    if(response->status == 200){
                        self->signupCount++;
                        self->serverResponse = nlohmann::json::parse(response->body);
                        std::cout << termcolor::green << "Success: " << self->serverResponse["message"] << termcolor::reset << std::endl;
                        QMetaObject::invokeMethod(self, [self, st](){
                            if(st.stop_requested()) std::exit(0);
                            if(self->signupCount == 1){
                                QMessageBox::information(self, "Success", "Successfully created an account, redirecting page now...");
                                emit self->account_page();
                            }
                        }, Qt::QueuedConnection);
                    }
                    else{
                        self->serverResponse = nlohmann::json::parse(response->body);
                        std::cerr << termcolor::red << "Message: " << self->serverResponse["message"] << termcolor::reset << std::endl;
                        QMetaObject::invokeMethod(self, [self, st](){
                            if(st.stop_requested()) std::exit(0);
                            QMessageBox::warning(self, "Error", QString::fromStdString(self->serverResponse["message"]));
                        }, Qt::QueuedConnection);
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

    loginCount = 0;
    QObject::disconnect(loginConnection);

    loginConnection = QObject::connect(loginButton, &QPushButton::clicked, [&](){
        loginCount++;
        if(loginCount == 1){
            QMessageBox::information(this, "Sign Up", "Redirecting to Login page");
            emit login_page();
        }
    });
}

void SignupWindow::reset(){
    firstNameLE->clear();
    middleNameLE->clear();
    lastNameLE->clear();

    un->clear();

    gen->clear();
    //uni->clear();
    dept->clear();
    lvl->clear();
    mn->clear();

    em->clear();
    pn->clear();

    pass1->clear();
    pass2->clear();
}
