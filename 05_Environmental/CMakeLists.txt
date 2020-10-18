cmake_minimum_required(VERSION 3.1)
project(05_Environmental C)

set(CMAKE_C_STANDARD 11)

find_library(CURSES_LIBRARY ncursesw)
find_library(PCRE_LIBRARY pcre2-8)

set(CURSES_NEED_NCURSES TRUE)
set(CURSES_NEED_WIDE TRUE)

if(WITHOUT_UTF)
    add_definitions(-DWITHOUT_UTF=1)
endif()

include(CheckIncludeFile)
check_include_file("ncurses.h" HAVE_NCURSES_H)
if(NOT HAVE_NCURSES_H)
    message( FATAL_ERROR "ncurses Not Found" )
endif()

add_executable(05_Environmental main.c)

target_link_libraries(05_Environmental ${CURSES_LIBRARY} ${PCRE_LIBRARY})
