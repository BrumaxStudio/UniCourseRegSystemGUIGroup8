#include <QApplication>
#include "unicouregsysgro8.hpp"
#include "termcolor/termcolor.hpp"
#include "argparse/argparse.hpp"
#include "creg8Version.h"

int main(int argc, char *argv[])
{
    std::string version = std::to_string(creg8_gui_VERSION_MAJOR + '.' + creg8_gui_VERSION_MINOR + '.' + creg8_gui_VERSION_PATCH);
    argparse::ArgumentParser program("University Course Registration System GUI", version);

    program.add_argument("-ip", "--ipaddress").nargs(1).default_value("localhost");
    program.add_argument("-p", "--port").nargs(1).default_value("8080");

    try {
        program.parse_args(argc, argv);
    }
    catch (std::exception& error) {
        std::cerr << termcolor::red << error.what();
        std::cerr << program << std::endl;
    }

    QApplication app(argc, argv);

    QString design = R"(QMainWindow, QWidget{
        background-color: rgb(170, 220, 230); color:black;
    })";

    app.setStyleSheet(design);

    std::cout << termcolor::green << "Database Project" << termcolor::reset << std::endl;
    std::cout << termcolor::green << "RSU-CPE311" << termcolor::reset << std::endl;
    std::cout << termcolor::green << "Graphical User Interface designed using Qt6" << termcolor::reset << std::endl;

    UniCouRegSysGro8 window;

    std::string arg1 = program.get<std::string>("-ip"), arg2 = program.get<std::string>("-p");

    window.passToServer(arg1, arg2);
    window.resize(800, 600);
    window.setWindowTitle("University Course Registration System - Group 8");
    window.show();

    return app.exec();
}
