#include "loginwindow.hpp"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget{parent}
{
    //Welcome label
    loginMessage = new QLabel(this);
    loginMessage->setText("Welcome to The Course Registration Portal!");
    loginMessage->setFont(QFont("Times", 29));
    loginMessage->setStyleSheet("color:yellow");

    rsuLogo = new QLabel(this);
    rsuLogo->setPixmap(QPixmap(":/rsu_logo256.jpg"));
    rsuLogo->setScaledContents(true);

    //Username
    emailForLogin = new QLabel(this);
    emailForLogin->setText("Email");
    emailForLogin->setFont(QFont("Times"));
    emailForLogin->setStyleSheet("color:gold");

    entryForEmail = new QLineEdit(this);
    entryForEmail->setPlaceholderText("Enter your username");
    entryForEmail->setFont(QFont("Times"));
    entryForEmail->setStyleSheet("color:gold");
    //Username

    //Password
    passwordForLogin = new QLabel(this);
    passwordForLogin->setText("Password");
    passwordForLogin->setFont(QFont("Times"));
    passwordForLogin->setStyleSheet("color:gold");

    entryForPassword = new QLineEdit(this);
    entryForPassword->setPlaceholderText("Enter your password");
    entryForPassword->setEchoMode(QLineEdit::Password);
    entryForPassword->setFont(QFont("Times"));
    entryForPassword->setStyleSheet("color:gold");
    //Password

    //University
    univer = new QLabel(this);
    univer->setText("University");
    univer->setFont(QFont("Times"));
    univer->setStyleSheet("color:gold");

    uni = new QComboBox(this);
    uni->addItem("Rivers State University");
    //University

    //Pushbutton - login
    loginButton = new QPushButton(this);
    loginButton->setText("Login");
    //Pushbutton - login

    //Pushbutton - signup
    SignupButton = new QPushButton(this);
    SignupButton->setText("Sign up");
    //Pushbutton - signup

    //NAME LAYOUT
    emailLayout = new QHBoxLayout;
    emailLayout->addWidget(emailForLogin);
    emailLayout->addWidget(entryForEmail);

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
    mainLayout->addLayout(emailLayout);
    mainLayout->addLayout(uniLayout);
    mainLayout->addLayout(passwordLayout);
    mainLayout->addLayout(loginORsignup);
    this->setLayout(mainLayout);

    QObject::connect(loginButton, &QPushButton::clicked, [&](){
        QString username = entryForEmail->text();
        QString password = entryForPassword->text();

        if(username.isEmpty() || password.isEmpty()){
            QMessageBox::warning(this, "Error", "Incomplete Credentials");
        }
        else{
            QMessageBox::information(this, "Success", "Login Successful");
            emit account_page();
        }
    });

    QObject::connect(SignupButton, &QPushButton::clicked, [&](){
        QMessageBox::information(this, "Sign Up", "Redirecting to Sign up page");
        emit signup_page();
    });
}

void LoginWindow::reset(){
    entryForEmail->clear();
    uni->clear();
    entryForPassword->clear();
}
