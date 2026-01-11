#include <QApplication>
#include "unicouregsysgro8.hpp"
#include "termcolor/termcolor.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString design = R"(QMainWindow, QWidget{
        background-color: rgb(170, 220, 230); color:black;
    })";

    app.setStyleSheet(design);

    std::cout << termcolor::green << "Database Project" << termcolor::reset << std::endl;
    std::cout << termcolor::green << "RSU-CPE311" << termcolor::reset << std::endl;
    std::cout << termcolor::green << "Graphical User Interface designed using Qt6" << termcolor::reset << std::endl;

    UniCouRegSysGro8 window;

    window.resize(800, 600);
    window.setWindowTitle("University Course Registration System - Group 8");
    window.show();

    return app.exec();
}
