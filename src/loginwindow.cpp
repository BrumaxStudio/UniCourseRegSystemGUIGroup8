#include "loginwindow.hpp"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget{parent}
{
    this->resize(800, 600);
    this->setWindowTitle("University Course Registration System");

    //Welcome label
    loginMessage = new QLabel(this);
    loginMessage->setText("Welcome to The Course Registration Portal!");
    loginMessage->setFont(QFont("Times", 29));
    loginMessage->setStyleSheet("color:yellow");

    rsuLogo = new QLabel(this);
    //rsuLogo->resize(150, 150);
    rsuLogo->setPixmap(QPixmap(":/rsu_logo.jpg"));
    rsuLogo->setScaledContents(true);

    //Username
    nameForLogin = new QLabel(this);
    nameForLogin->setText("Username");
    nameForLogin->setFont(QFont("Times"));
    nameForLogin->setStyleSheet("color:gold");

    entryForName = new QLineEdit(this);
    entryForName->setPlaceholderText("Enter your username");
    entryForName->setFont(QFont("Times"));
    entryForName->setStyleSheet("color:gold");
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
    ptr->addWidget(rsuLogo);
    ptr->addLayout(nameLayout);
    ptr->addLayout(passwordLayout);
    ptr->addLayout(loginORsignup);
    this->setLayout(ptr);

    QObject::connect(loginButton, &QPushButton::clicked, [&](){
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
    });
}
