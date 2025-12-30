#include <QApplication>
#include "loginwindow.hpp"
#include "signupwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qInfo() << "Database Project";
    qInfo() << "RSU-CPE311";
    qInfo() << "Graphical User Interface designed using Qt6";

    //Main window
    QStackedWidget screenChanger;

    //Login Window
    LoginWindow log(&screenChanger);
    SignupWindow sig(&screenChanger);

    screenChanger.addWidget(&log);
    screenChanger.addWidget(&sig);

    screenChanger.resize(800, 600);
    screenChanger.setWindowTitle("University Course Registration System");
    screenChanger.show();

    return app.exec();
}
