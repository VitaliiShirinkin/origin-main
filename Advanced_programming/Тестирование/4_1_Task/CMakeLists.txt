# CMakeList.txt: проект CMake для 4_1_Task; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("4_1_Task")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (4_1_Task "test_1.cpp")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}../../Catch2 Catch2-build)
target_link_libraries(4_1_Task PRIVATE Catch2::Catch2)
