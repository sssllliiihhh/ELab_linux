# CMakeList.txt: проект CMake для ELab; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

find_package(SDL2 REQUIRED)

add_executable (ELab "ELab.cpp" "ELab.h")
target_link_libraries(ELab SDL2::SDL2 SDL2::SDL2main)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ELab PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
