cmake_minimum_required(VERSION 3.10)

project(calculator C)

add_library(calculator SHARED
    src/calculator.c
    src/lexer.c
    src/parser.c
    src/error.c
)

target_include_directories(calculator PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(calculator m)

install(TARGETS calculator
    LIBRARY DESTINATION lib
)

install(
    FILES include/calculator.h include/error.h
    DESTINATION include
)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -E rm -rf
    "${CMAKE_INSTALL_PREFIX}/include/calculator.h"
    "${CMAKE_INSTALL_PREFIX}/lib/libcalculator.so"
    "${CMAKE_CURRENT_SOURCE_DIR}/build"
    COMMENT "Uninstalling calculator library"
)
