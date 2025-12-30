cmake_minimum_required(VERSION 3.30)

project(UniCourseRegSystemGUIGroup8 VERSION 2025.12.30 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(LINUX)
    add_compile_options(
        -Wall
        -Wextra
        -Werror
        -Wpedantic
    )
endif(LINUX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(SRC_FILES
    include/loginwindow.hpp
    src/loginwindow.cpp
    include/signupwindow.hpp
    src/signupwindow.cpp
    src/main.cpp
)

qt_standard_project_setup()

qt_add_resources(SRC_FILES resources/uniCourseRegGroup8.qrc)

qt_add_executable(${PROJECT_NAME}
    ${SRC_FILES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Core Qt6::Widgets Qt6::Gui
)

#include(GNUInstallDirs)
#install(TARGETS ${PROJECT_NAME}
    #BUNDLE DESTINATION .
    #LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    #RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#)
