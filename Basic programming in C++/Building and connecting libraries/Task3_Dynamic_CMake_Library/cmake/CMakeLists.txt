cmake_minimum_required (VERSION 3.10)
set (CMAKE_CXX_STANDART 20)
set (CMAKE_CXX_STANDART_REQUIRED True)
project (project)

include_directories (Task2_Dynamic_library)

#set (SOURCES_LIB Leaver.cpp Leaver.h)
set (SOURCES_EXE LeaverClient.cpp)
add_executable (project ${SOURCES_EXE} )

add_subdirectory (Task2_Dynamic_library)
target_link_libraries (project Leaver_dll)
