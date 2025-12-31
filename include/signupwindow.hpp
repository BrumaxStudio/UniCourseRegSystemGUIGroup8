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

    QVBoxLayout* mainLayout;
};

#endif // SIGNUPWINDOW_HPP
