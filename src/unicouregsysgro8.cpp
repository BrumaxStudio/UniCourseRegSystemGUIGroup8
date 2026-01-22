#include "unicouregsysgro8.hpp"

UniCouRegSysGro8::UniCouRegSysGro8(QWidget *parent)
    : QMainWindow{parent}
{
    screenChanger = new QStackedWidget(this);
    log = new LoginWindow(this);
    sig = new SignupWindow(this);
    acc = new AccountPageWindow(this);

    screenChanger->addWidget(log);
    screenChanger->addWidget(sig);
    screenChanger->addWidget(acc);

    this->setCentralWidget(screenChanger);

    //Resets page and redirects page to the account page
    QObject::connect(log, &LoginWindow::account_page, this, [this](){
        if(!log->serverResponse.empty()) acc->dataM = log->serverResponse;
        acc->refreshPage();
        screenChanger->setCurrentWidget(acc);
        log->reset();
    });

    //Resets page and redirects page to the signup page
    QObject::connect(log, &LoginWindow::signup_page, this, [this](){
        screenChanger->setCurrentWidget(sig);
        log->reset();
        sig->refreshPage();
    });

    //Resets page and redirects page to the account page
    QObject::connect(sig, &SignupWindow::account_page, this, [this](){
        if(!sig->serverResponse.empty()) acc->dataM = sig->serverResponse;
        acc->refreshPage();
        screenChanger->setCurrentWidget(acc);
        sig->reset();
    });

    //Resets page and redirects page to the login page
    QObject::connect(sig, &SignupWindow::login_page, this, [this](){
        screenChanger->setCurrentWidget(log);
        sig->reset();
        log->refreshPage();
    });

    //Resets page and redirects page to the login page
    QObject::connect(acc, &AccountPageWindow::login_page, this, [this](){
        screenChanger->setCurrentWidget(log);
        acc->reset();
        log->refreshPage();
    });

    //Resets page and redirects page to the signup page
    QObject::connect(acc, &AccountPageWindow::signup_page, this, [this](){
        screenChanger->setCurrentWidget(sig);
        acc->reset();
        sig->refreshPage();
    });
}

void UniCouRegSysGro8::connectToServer(std::string ipAddress, std::string portNumber){
    sig->ipAddress = QString::fromStdString(ipAddress);
    sig->portNumber = QString::fromStdString(portNumber);

    log->ipAddress = QString::fromStdString(ipAddress);
    log->portNumber = QString::fromStdString(portNumber);
}

void UniCouRegSysGro8::passToServer(std::string ipAddress, std::string portNumber){
    this->connectToServer(ipAddress, portNumber);
}
