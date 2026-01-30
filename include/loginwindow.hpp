#ifndef LOGINWINDOW_HPP
#define LOGINWINDOW_HPP

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QString>
#include <QComboBox>
#include <QPointer>

#include <nlohmann/json.hpp>
#include <termcolor/termcolor.hpp>
#include <httplib.h>

#include <iostream>
#include <thread>

class LoginWindow : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = nullptr);

signals:
    void signup_page();
    void account_page();

public:
    void reset();
    void refreshPage();
    QString ipAddress;
    QString portNumber;
    nlohmann::json serverResponse;
    nlohmann::json reader_json;

    QMetaObject::Connection loginConnection;
    QMetaObject::Connection SignupConnection;

private:
    int loginCount;
    int signupCount;

    QLabel* rsuLogo;

    QLabel* loginMessage;

    QLabel* userNameForLogin;
    QLineEdit* entryForUserName;

    QLabel* passwordForLogin;
    QLineEdit* entryForPassword;

    QPushButton* loginButton;
    QPushButton* SignupButton;

    QHBoxLayout* loginORsignup;

    QLabel* univer;
    QComboBox* uni;
    QHBoxLayout* uniLayout;

    QHBoxLayout* UserNameLayout;
    QHBoxLayout* passwordLayout;

    QVBoxLayout* mainLayout;
};

#endif // LOGINWINDOW_HPP
