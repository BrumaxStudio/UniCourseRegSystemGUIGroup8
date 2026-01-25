cmake_minimum_required(VERSION 3.30)

project(creg8_gui VERSION 2026.1.25 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_BUILD_PARALLEL 8)
set(APPLICATION_NAME "creg8-gui")
set(BOOST_REGEX_STANDALONE ON CACHE BOOL "Build Boost.Regex in standalone mode")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

configure_file(creg8Version.h.in ${PROJECT_BINARY_DIR}/creg8Version.h)

add_subdirectory(third_party/json)
add_subdirectory(third_party/termcolor)
add_subdirectory(third_party/argparse)
add_subdirectory(third_party/cpp-httplib)
add_subdirectory(third_party/regex)

set(SRC_FILES
    include/loginwindow.hpp
    src/loginwindow.cpp
    include/signupwindow.hpp
    src/signupwindow.cpp
    include/unicouregsysgro8.hpp
    src/unicouregsysgro8.cpp
    include/accountpagewindow.hpp
    src/accountpagewindow.cpp
    src/main.cpp
    resources/creg-gui.rc
)

qt_standard_project_setup()

qt_add_resources(SRC_FILES resources/uniCourseRegGroup8.qrc)

qt_add_executable(${APPLICATION_NAME}
    ${SRC_FILES}
)

if(LINUX)
    target_compile_options(${APPLICATION_NAME}
        PRIVATE
        -Wall
        -Wextra
        -Werror
        -Wpedantic  
    )
endif(LINUX)

set_target_properties(${APPLICATION_NAME} PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE False
)

target_include_directories(${APPLICATION_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/regex/include
    ${PROJECT_BINARY_DIR}
)

target_link_libraries(${APPLICATION_NAME}
    PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
    nlohmann_json
    termcolor
    argparse
    httplib
    Boost::regex
)
