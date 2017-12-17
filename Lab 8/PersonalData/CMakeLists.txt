cmake_minimum_required(VERSION 3.9)
project(PersonalData C)

set(CMAKE_C_STANDARD 99)

add_executable(PersonalData main.c Main.c Person.c Person.h PeopleStorage.c PeopleStorage.h Debugger.c Debugger.h)