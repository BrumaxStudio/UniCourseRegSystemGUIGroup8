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
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <thread>
#include <chrono>
#include <fstream>
#include <string>
#include <expected>

#include "nlohmann/json.hpp"
#include "termcolor/termcolor.hpp"
#include <type_traits>

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
    void refreshPage();

    QString ipAddress;
    QString portNumber;
    nlohmann::json serverResponse;

private:
    template<class T> std::expected<T, bool> getInput(QLineEdit* LE){
        int good = 0;
        bool  bad = false;

        try {
            if(std::is_same_v<int, T>){
                good = std::stoi(LE->text().toStdString());
                return good;
            }
            else if(std::is_same_v<long long, T>){
                good = std::stoll(LE->text().toStdString());
                return good;
            }

        } catch (const std::exception& error) {
            return std::unexpected(bad);
        }
    }

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

    QLabel* matricNO;
    QLineEdit* mn;
    QHBoxLayout* mnLayout;

    QLabel* email_add;
    QLineEdit* em;

    QLabel* phone_no;
    QLineEdit* pn;

    QHBoxLayout* emailLayout;
    QHBoxLayout* phoneNoLayout;

    QLabel* univer;
    QComboBox* uni;
    QHBoxLayout* uniLayout;

    QLabel* userName;
    QLineEdit* un;
    QHBoxLayout* userNameLayout;

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
