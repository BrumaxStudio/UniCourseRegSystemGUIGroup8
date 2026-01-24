#ifndef UNICOUREGSYSGRO8_HPP
#define UNICOUREGSYSGRO8_HPP

#include <string>

#include <QMainWindow>
#include <QStackedWidget>
#include <QCloseEvent>
#include <QCoreApplication>

#include "loginwindow.hpp"
#include "signupwindow.hpp"
#include "accountpagewindow.hpp"

class UniCouRegSysGro8 : public QMainWindow
{
    Q_OBJECT
public:
    explicit UniCouRegSysGro8(QString ipAddress, QString portNumber, QWidget *parent = nullptr);

private:
    QStackedWidget* screenChanger;

    LoginWindow* log;
    SignupWindow* sig;
    AccountPageWindow* acc;

public:
    void passToServer(std::string ipAddress, std::string portNumber);

private:
    void connectToServer(std::string ipAddress, std::string portNumber);
};

#endif // UNICOUREGSYSGRO8_HPP
