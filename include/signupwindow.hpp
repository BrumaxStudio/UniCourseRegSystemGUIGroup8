#ifndef SIGNUPWINDOW_HPP
#define SIGNUPWINDOW_HPP

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QMessageBox>
#include <QComboBox>

class SignupWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SignupWindow(QStackedWidget* parentSW, QWidget *parent = nullptr);

private:
    QStackedWidget* screenChanger;

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

    QHBoxLayout* firstNameLayout;
    QHBoxLayout* middleNameLayout;
    QHBoxLayout* lastNameLayout;

    QHBoxLayout* genderLayout;

    QHBoxLayout* deptLayout;

    QVBoxLayout* mainLayout;
};

#endif // SIGNUPWINDOW_HPP
