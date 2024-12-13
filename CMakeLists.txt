cmake_minimum_required(VERSION 3.10)
project(ELab)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

add_executable(ELab main.cpp)

include_directories(${GTK_INCLUDE_DIRS})
target_link_libraries(ELab ${GTK_LIBRARIES})

