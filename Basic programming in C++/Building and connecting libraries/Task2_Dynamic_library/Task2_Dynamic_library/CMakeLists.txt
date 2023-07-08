cmake_minimum_required (VERSION 3.10)
set (CMAKE_CXX_STANDART 20)
set (CMAKE_CXX_STANDART_REQUIRED True)
project (Leaver_lib)

#set (SOURCES_LIB Leaver.cpp Leaver.h)
set (SOURCES_DLL Leaver.cpp Leaver.h)

#add_library (Leaver_lib STATIC ${SOURCES_DLL} )
add_library (Leaver_dll SHARED ${SOURCES_DLL} )
