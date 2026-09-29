add_executable(creg8-gui2)
target_sources(creg8-gui2
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/slint/sources/Creg_Main.cpp
)
slint_target_sources(creg8-gui2 ${CMAKE_SOURCE_DIR}/src/slint/ui/Creg8_Main.slint)
target_link_libraries(creg8-gui2 PRIVATE Slint::Slint ${FONTCONFIG_LIBRARIES})
target_include_directories(creg8-gui2 PRIVATE ${CMAKE_SOURCE_DIR}/${CMAKE_BINARY_DIR})