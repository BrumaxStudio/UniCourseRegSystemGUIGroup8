add_executable(creg8-gui2)

target_sources(creg8-gui2
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/slint/sources/Creg_Main.cpp
    PRIVATE
        FILE_SET CXX_MODULES
        TYPE CXX_MODULES
        FILES
            ${CMAKE_SOURCE_DIR}/src/slint/sources/Creg_Network.cpp
)

slint_target_sources(creg8-gui2 ${CMAKE_SOURCE_DIR}/src/slint/ui/Creg8_Main.slint)

target_link_libraries(creg8-gui2
    PRIVATE
        Slint::Slint
        ${FONTCONFIG_LIBRARIES}
        nlohmann_json
        termcolor
        argparse
        httplib
        Boost::regex
)

target_include_directories(creg8-gui2
    PRIVATE
        ${CMAKE_SOURCE_DIR}/${CMAKE_BINARY_DIR}
        ${PROJECT_BINARY_DIR}
        ${CMAKE_SOURCE_DIR}/third_party/regex/include
)
