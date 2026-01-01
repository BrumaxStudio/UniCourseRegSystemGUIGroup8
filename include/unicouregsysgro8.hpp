#ifndef UNICOUREGSYSGRO8_HPP
#define UNICOUREGSYSGRO8_HPP

#include <QMainWindow>
#include <QStackedWidget>
#include "loginwindow.hpp"
#include "signupwindow.hpp"
#include "accountpagewindow.hpp"

class UniCouRegSysGro8 : public QMainWindow
{
    Q_OBJECT
public:
    explicit UniCouRegSysGro8(QWidget *parent = nullptr);

private:
    QStackedWidget* screenChanger;

    LoginWindow* log;
    SignupWindow* sig;
    AccountPageWindow* acc;
};

#endif // UNICOUREGSYSGRO8_HPP
