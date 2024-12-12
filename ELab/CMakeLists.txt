cmake_minimum_required(VERSION 3.16)
project(ELab)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS})

add_executable(ELab "ELab.cpp" "ELab.h")
target_link_libraries(ELab ${SDL2_LIBRARIES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ELab PROPERTY CXX_STANDARD 20)
endif()
