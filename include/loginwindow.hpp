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
#include <QStackedWidget>

class LoginWindow : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWindow(QStackedWidget* parentSW, QWidget *parent = nullptr);

private:
    QStackedWidget* screenChanger;

    QLabel* rsuLogo;

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

    QVBoxLayout* mainLayout;
};

#endif // LOGINWINDOW_HPP
