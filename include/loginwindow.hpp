#ifndef LOGINWINDOW_HPP
#define LOGINWINDOW_HPP

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class LoginWindow : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = nullptr);

private:
    QLabel* loginMessage;

    QLabel* nameForLogin;
    QLineEdit* entryForName;

    QLabel* passwordForLogin;
    QLineEdit* entryForPassword;

    QPushButton* loginButton;
    QPushButton* SignupButton;

    QHBoxLayout* loginORsignup;

    QHBoxLayout* nameLayout;
    QHBoxLayout* passwordLayout;

    QVBoxLayout* ptr;
};

#endif // LOGINWINDOW_HPP
