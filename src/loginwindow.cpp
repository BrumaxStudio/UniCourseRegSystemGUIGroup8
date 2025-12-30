#include "loginwindow.hpp"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget{parent}
{
    this->resize(800, 600);
    this->setWindowTitle("University Course Registration System");

    //Welcome label
    loginMessage = new QLabel(this);
    loginMessage->setText("Welcome to The Course Registration Portal");
    loginMessage->setFont(QFont("Times"));
    loginMessage->setStyleSheet("color:yellow");

    //Username
    nameForLogin = new QLabel(this);
    nameForLogin->setText("Username");
    nameForLogin->setFont(QFont("Times"));
    nameForLogin->setStyleSheet("color:red");

    entryForName = new QLineEdit(this);
    entryForName->setPlaceholderText("Enter your username");
    entryForName->setFont(QFont("Times"));
    entryForName->setStyleSheet("color:red");
    //Username

    //Password
    passwordForLogin = new QLabel(this);
    passwordForLogin->setText("Password");
    passwordForLogin->setFont(QFont("Times"));
    passwordForLogin->setStyleSheet("color:green");

    entryForPassword = new QLineEdit(this);
    entryForPassword->setPlaceholderText("Enter your password");
    entryForPassword->setEchoMode(QLineEdit::Password);
    entryForPassword->setFont(QFont("Times"));
    entryForPassword->setStyleSheet("color:green");
    //Password

    //Pushbutton - login
    loginButton = new QPushButton(this);
    loginButton->setText("Login");
    //Pushbutton - login

    //Pushbutton - signup
    SignupButton = new QPushButton(this);
    SignupButton->setText("Sign up");
    //Pushbutton - signup

    nameLayout = new QHBoxLayout;
    nameLayout->addWidget(nameForLogin);
    nameLayout->addWidget(entryForName);

    passwordLayout = new QHBoxLayout;
    passwordLayout->addWidget(passwordForLogin);
    passwordLayout->addWidget(entryForPassword);

    loginORsignup = new QHBoxLayout;
    loginORsignup->addWidget(loginButton);
    loginORsignup->addWidget(SignupButton);

    ptr = new QVBoxLayout;
    ptr->addWidget(loginMessage);
    ptr->addLayout(nameLayout);
    ptr->addLayout(passwordLayout);
    ptr->addLayout(loginORsignup);

    this->setLayout(ptr);
}
