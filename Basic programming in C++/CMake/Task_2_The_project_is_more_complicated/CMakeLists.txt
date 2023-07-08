cmake_minimum_required (VERSION 3.10)
project (project2)

set (SOURSE_FILE equilTriangle.cpp equilTriangle.h Figure.cpp Figure.h isosTriangle.cpp isosTriangle.h parallelogram.cpp parallelogram.h Quadrangle.cpp Quadrangle.h rectangle.cpp rectangle.h rhomb.cpp rhomb.h rightTriangle.cpp rightTriangle.h square.cpp square.h Triangle.cpp Triangle.h Task_3_Class_hierarchy.cpp)

add_executable (project2 ${SOURSE_FILE} )