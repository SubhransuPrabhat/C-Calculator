cmake_minimum_required(VERSION 4.4)

project(calculator)

add_library(calculator SHARED
    src/calculator.c
    src/lexer.c
    src/parser.c
)

target_include_directories(calculator PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install(TARGETS calculator
    LIBRARY DESTINATION lib
)

install(
    FILES include/calculator.h
    DESTINATION include
)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -E rm -f
    "${CMAKE_INSTALL_PREFIX}/include/calculator.h"
    "${CMAKE_INSTALL_PREFIX}/lib/libcalculator.so"
    COMMENT "Uninstalling calculator library"
)
