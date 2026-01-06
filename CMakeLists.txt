cmake_minimum_required(VERSION 3.30)

project(UniCourseRegSystemGUIGroup8 VERSION 2026.1.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_subdirectory(third_party/Bcrypt.cpp)
add_subdirectory(third_party/json)

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
)

qt_standard_project_setup()

qt_add_resources(SRC_FILES resources/uniCourseRegGroup8.qrc)

qt_add_executable(${PROJECT_NAME}
    ${SRC_FILES}
)

if(LINUX)
    target_compile_options(${PROJECT_NAME}
        PRIVATE
        -Wall
        -Wextra
        -Wno-error=format
        -Werror
        -Wpedantic
    )
endif(LINUX)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
    bcrypt
    nlohmann_json
)
