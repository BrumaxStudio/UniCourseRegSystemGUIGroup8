#include "signupwindow.hpp"

SignupWindow::SignupWindow(QStackedWidget* parentSW, QWidget *parent)
    : QWidget{parent}, screenChanger(parentSW)
{
    //Welcome label
    SigningLabel = new QLabel(this);
    SigningLabel->setText("Create an account and register courses");
    SigningLabel->setFont(QFont("Times", 25));
    SigningLabel->setStyleSheet("color:yellow");

    //First name - required
    first_name = new QLabel(this);
    first_name->setText("First name");
    first_name->setFont(QFont("Times"));
    first_name->setStyleSheet("color:yellow");
    //First name - required

    //Middle name - optional
    //Middle name - optional

    //last name - required
    //last name - required

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
