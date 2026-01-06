#ifndef SIGNUPWINDOW_HPP
#define SIGNUPWINDOW_HPP

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QComboBox>
#include <QString>
#include <QPointer>

#include <thread>
#include <chrono>
#include <fstream>

#include "bcrypt.h"
#include "nlohmann/json.hpp"

class SignupWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SignupWindow(QWidget *parent = nullptr);

signals:
    void login_page();
    void account_page();

public:
    void reset();

private:
    std::jthread hash_thread;
    nlohmann::json json_reader;

    QLabel* SigningLabel;

    QLabel* rsuLogo;

    QLabel* first_name;
    QLabel* middle_name;
    QLabel* last_name;

    QLineEdit* firstNameLE;
    QLineEdit* middleNameLE;
    QLineEdit* lastNameLE;

    QLabel* gender;
    QComboBox* gen;

    QLabel* department;
    QComboBox* dept;

    QLabel* level;
    QComboBox* lvl;

    QLabel* email_add;
    QLineEdit* em;

    QLabel* phone_no;
    QLineEdit* pn;

    QHBoxLayout* emailLayout;
    QHBoxLayout* phoneNoLayout;

    QLabel* univer;
    QComboBox* uni;
    QHBoxLayout* uniLayout;

    QPushButton* loginButton;
    QPushButton* SignupButton;

    QHBoxLayout* loginORsignup;

    QLabel* password1;
    QLabel* password2;
    QLineEdit* pass1;
    QLineEdit* pass2;
    QHBoxLayout* passwordLayout1;
    QHBoxLayout* passwordLayout2;

    QHBoxLayout* firstNameLayout;
    QHBoxLayout* middleNameLayout;
    QHBoxLayout* lastNameLayout;

    QHBoxLayout* genderLayout;

    QHBoxLayout* deptLayout;

    QHBoxLayout* levelLayout;

    QVBoxLayout* mainLayout;
};

#endif // SIGNUPWINDOW_HPP
