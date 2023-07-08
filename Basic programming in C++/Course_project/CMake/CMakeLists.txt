cmake_minimum_required(VERSION 3.10)
project(Vehicle)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(VehiclesLibraryDynamic SHARED
	"DynamicVehicles/DynamicVehicles.h"
	"DynamicVehicles/DynamicVehicles.cpp"
	"GraundVehicles/GraundVehicles.h"
	"GraundVehicles/GraundVehicles.cpp"
	"GraundVehicles/Camel.h"
	"GraundVehicles/Camel.cpp"
	"GraundVehicles/CamelSpeedWalker.h"
	"GraundVehicles/CamelSpeedWalker.cpp"
	"GraundVehicles/Centaur.h"
	"GraundVehicles/Centaur.cpp"
	"GraundVehicles/BootsAllTerrain.h"
	"GraundVehicles/BootsAllTerrain.cpp"
	"Functions.h"
	"Functions.cpp"
	"AirVehicles/AirVehicles.h"
	"AirVehicles/AirVehicles.cpp"
	"AirVehicles/CarpetPlane.h"
	"AirVehicles/CarpetPlane.cpp"
	"AirVehicles/Eagle.h"
	"AirVehicles/Eagle.cpp"
	"AirVehicles/Broom.h"
	"AirVehicles/Broom.cpp")
 
add_executable(Vehicle main.cpp)
target_link_libraries(Vehicle VehiclesLibraryDynamic)