#include "signupwindow.hpp"

SignupWindow::SignupWindow(QWidget *parent)
    : QWidget{parent}
{
    //Welcome label
    SigningLabel = new QLabel(this);
    SigningLabel->setText("Create an account and register courses");
    SigningLabel->setFont(QFont("Times", 25));
    SigningLabel->setStyleSheet("color:gold");
    //Welcome label

    rsuLogo = new QLabel(this);
    rsuLogo->setPixmap(QPixmap(":/rsu_logo256.jpg"));
    rsuLogo->setScaledContents(true);

    //First name - required
    first_name = new QLabel(this);
    first_name->setText("First name");
    first_name->setFont(QFont("Times"));
    first_name->setStyleSheet("color:gold");

    firstNameLE = new QLineEdit(this);
    firstNameLE->setPlaceholderText("Required");
    firstNameLE->setFont(QFont("Times"));
    firstNameLE->setStyleSheet("color:gold");
    //First name - required

    //Middle name - optional
    middle_name = new QLabel(this);
    middle_name->setText("Middle name");
    middle_name->setFont(QFont("Times"));
    middle_name->setStyleSheet("color:gold");

    middleNameLE = new QLineEdit(this);
    middleNameLE->setPlaceholderText("Optional");
    middleNameLE->setFont(QFont("Times"));
    middleNameLE->setStyleSheet("color:gold");
    //Middle name - optional

    //last name - required
    last_name = new QLabel(this);
    last_name->setText("Last name");
    last_name->setFont(QFont("Times"));
    last_name->setStyleSheet("color:gold");

    lastNameLE = new QLineEdit(this);
    lastNameLE->setPlaceholderText("Required");
    lastNameLE->setFont(QFont("Times"));
    lastNameLE->setStyleSheet("color:gold");
    //last name - required

    //Gender/Sex
    gender = new QLabel(this);
    gender->setText("Select your gender");
    gender->setFont(QFont("Times"));
    gender->setStyleSheet("color:gold");

    gen = new QComboBox(this);
    gen->addItem("Male");
    gen->addItem("Female");
    gen->addItem("Prefer not to say");
    //Gender/Sex

    //Department
    department = new QLabel(this);
    department->setText("Department");
    department->setFont(QFont("Times"));
    department->setStyleSheet("color:gold");

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

    //University
    univer = new QLabel(this);
    univer->setText("University");
    univer->setFont(QFont("Times"));
    univer->setStyleSheet("color:gold");

    uni = new QComboBox(this);
    uni->addItem("Rivers State University");
    //University

    //Email and Phone No
    email_add = new QLabel(this);
    email_add->setText("Email");
    email_add->setFont(QFont("Times"));
    email_add->setStyleSheet("color:gold");

    em = new QLineEdit(this);
    em->setPlaceholderText("Required");
    em->setFont(QFont("Times"));
    em->setStyleSheet("color:gold");

    phone_no = new QLabel(this);
    phone_no->setText("Phone number");
    phone_no->setFont(QFont("Times"));
    phone_no->setStyleSheet("color:gold");

    pn = new QLineEdit(this);
    pn->setPlaceholderText("Required");
    pn->setFont(QFont("Times"));
    pn->setStyleSheet("color:gold");
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
    password1->setStyleSheet("color:gold");

    pass1 = new QLineEdit(this);
    pass1->setPlaceholderText("Enter new password");
    pass1->setEchoMode(QLineEdit::Password);
    pass1->setFont(QFont("Times"));
    pass1->setStyleSheet("color:gold");

    //second
    password2= new QLabel(this);
    password2->setText("Re-enter Password");
    password2->setFont(QFont("Times"));
    password2->setStyleSheet("color:gold");

    pass2 = new QLineEdit(this);
    pass2->setPlaceholderText("Enter password again");
    pass2->setEchoMode(QLineEdit::Password);
    pass2->setFont(QFont("Times"));
    pass2->setStyleSheet("color:gold");
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

    //MAIN LAYOUT
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(SigningLabel);
    mainLayout->addWidget(rsuLogo);
    mainLayout->addLayout(firstNameLayout);
    mainLayout->addLayout(middleNameLayout);
    mainLayout->addLayout(lastNameLayout);
    mainLayout->addLayout(genderLayout);
    mainLayout->addLayout(deptLayout);
    mainLayout->addLayout(uniLayout);
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

        QString gen_v = gen->currentText();
        QString dept_v = dept->currentText();

        QString password_1_v = pass1->text();
        QString password_2_v = pass2->text();

        if(f_name.isEmpty() || l_name.isEmpty() || gen_v.isEmpty() || dept_v.isEmpty()){
            QMessageBox::warning(this, "Error", "Incomplete Details!");
        }
        else if(password_1_v != password_2_v){
            QMessageBox::warning(this, "Error", "Passwords don't match!");
        }
        else{
            QMessageBox::information(this, "Success", "Successfully created account, redirecting page now...");
            emit account_page();
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

    pass1->clear();
    pass2->clear();
}
