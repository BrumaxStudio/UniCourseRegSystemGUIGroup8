#include "unicouregsysgro8.hpp"

UniCouRegSysGro8::UniCouRegSysGro8(QString ipAddress, QString portNumber, QWidget *parent)
    : QMainWindow{parent}
{
    screenChanger = new QStackedWidget(this);
    log = new LoginWindow(this);
    sig = new SignupWindow(this);
    acc = new AccountPageWindow(this);

    log->ipAddress = ipAddress;
    log->portNumber = portNumber;

    sig->ipAddress = ipAddress;
    sig->portNumber = portNumber;

    acc->ipAddress = ipAddress;
    acc->portNumber = portNumber;

    screenChanger->addWidget(log);
    screenChanger->addWidget(sig);
    screenChanger->addWidget(acc);

    this->setCentralWidget(screenChanger);

    //Resets page and redirects page to the account page
    QObject::connect(log, &LoginWindow::account_page, this, [this](){
        if(!log->serverResponse.empty()){
            acc->dataM = log->serverResponse;
            acc->userName = QString::fromStdString(log->reader_json["user_name"].get<std::string>());
        }
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
        if(!sig->serverResponse.empty()){
            acc->dataM = sig->serverResponse;
            acc->userName = QString::fromStdString(sig->reader_json["student"]["user_name"]);
        }
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

    //Refreshes page
    QObject::connect(acc, &AccountPageWindow::reload_page, this, [this](){
        //screenChanger->setCurrentWidget(acc);
        if(!acc->dataMMM.empty()){
            acc->dataM = acc->dataMMM;
            acc->userName = QString::fromStdString(acc->reader_json["user_name"].get<std::string>());
        }
        acc->reset();
        acc->refreshPage();
    });
}
