#include "signupwindow.hpp"

SignupWindow::SignupWindow(QStackedWidget* parentSW, QWidget *parent)
    : QWidget{parent}, screenChanger(parentSW)
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

    //login and sign up
    loginButton = new QPushButton(this);
    loginButton->setText("Already have an account");

    SignupButton = new QPushButton(this);
    SignupButton->setText("Sign up");
    //login and sign up

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

    //MAIN LAYOUT
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(SigningLabel);
    mainLayout->addWidget(rsuLogo);
    mainLayout->addLayout(firstNameLayout);
    mainLayout->addLayout(middleNameLayout);
    mainLayout->addLayout(lastNameLayout);
    mainLayout->addLayout(genderLayout);
    mainLayout->addLayout(deptLayout);
    mainLayout->addLayout(loginORsignup);

    this->setLayout(mainLayout);
    //MAIN LAYOUT

    /*QObject::connect(loginButton, &QPushButton::clicked, [&](){
        QString username = entryForName->text();
        QString password = entryForPassword->text();

        if(username.isEmpty() || password.isEmpty()){
            QMessageBox::warning(this, "Error", "Incomplete Credentials");
        }
        else{
            QMessageBox::information(this, "Success", "Login Successful");
        }
    });

    QObject::connect(SignupButton, &QPushButton::clicked, [&](){
        QMessageBox::information(this, "Sign Up", "Redirecting to Sign up page");
        screenChanger->setCurrentIndex(1);
    });*/
}
