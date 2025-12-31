#include <QApplication>
#include "unicouregsysgro8.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qInfo() << "Database Project";
    qInfo() << "RSU-CPE311";
    qInfo() << "Graphical User Interface designed using Qt6";

    UniCouRegSysGro8 window;

    window.resize(800, 600);
    window.setWindowTitle("University Course Registration System - Group 8");
    window.show();

    return app.exec();
}
