cmake_minimum_required (VERSION 3.8)

project ("3.2_Smart_arrays_copying")

add_executable (3.2_Smart_arrays_copying "3.2_Smart_arrays_copying.cpp" "Exception.h" "Exception.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 3.2_Smart_arrays_copying PROPERTY CXX_STANDARD 20)
endif()