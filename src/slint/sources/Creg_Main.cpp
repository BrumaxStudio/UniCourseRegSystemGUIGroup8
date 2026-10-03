#include <slint.h>
#include "argparse/argparse.hpp"
#include "termcolor/termcolor.hpp"

#include <Creg8_Main.h>
#include "creg8Version.h"

import creg_network;

int main(int argc, char** argv){
    Cregn::Net();

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

    auto Application = Creg8_Window::create();
    Application->run();
}