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

private:
    QLabel* rsuLogo;

    QLabel* loginMessage;

    QLabel* emailForLogin;
    QLineEdit* entryForEmail;

    QLabel* passwordForLogin;
    QLineEdit* entryForPassword;

    QPushButton* loginButton;
    QPushButton* SignupButton;

    QHBoxLayout* loginORsignup;

    QLabel* univer;
    QComboBox* uni;
    QHBoxLayout* uniLayout;

    QHBoxLayout* emailLayout;
    QHBoxLayout* passwordLayout;

    QVBoxLayout* mainLayout;
};

#endif // LOGINWINDOW_HPP
