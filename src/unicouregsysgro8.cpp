#include "unicouregsysgro8.hpp"

UniCouRegSysGro8::UniCouRegSysGro8(QWidget *parent)
    : QMainWindow{parent}
{
    screenChanger = new QStackedWidget(this);
    log = new LoginWindow(this);
    sig = new SignupWindow(this);

    screenChanger->addWidget(log);
    screenChanger->addWidget(sig);

    this->setCentralWidget(screenChanger);

    //screenChanger->se
    //Resets page and redirects page to the account page
    QObject::connect(log, &LoginWindow::account_page, this, [this](){
        log->reset();
        //screenChanger->setCurrentIndex(2);
    });

    //Resets page and redirects page to the signup page
    QObject::connect(log, &LoginWindow::signup_page, this, [this](){
        log->reset();
        screenChanger->setCurrentIndex(1);
    });

    //Resets page and redirects page to the account page
    QObject::connect(sig, &SignupWindow::account_page, this, [this](){
        sig->reset();
        //screenChanger->setCurrentIndex(2);
    });

    //Resets page and redirects page to the login page
    QObject::connect(sig, &SignupWindow::login_page, this, [this](){
        sig->reset();
        screenChanger->setCurrentIndex(0);
    });
}
