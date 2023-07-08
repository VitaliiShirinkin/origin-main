//Заголовочный файл функций проекта

#pragma once
#include <iostream>
#include "GraundVehicles/Camel.h"
#include "GraundVehicles/CamelSpeedWalker.h"
#include "GraundVehicles/Centaur.h"
#include "GraundVehicles/BootsAllTerrain.h"
#include "DynamicVehicles/DynamicVehicles.h"
#include "AirVehicles/Broom.h"
#include "AirVehicles/CarpetPlane.h"
#include "AirVehicles/Eagle.h"


// Функция выбора типа гонки
VEHICLESLIBRARY_API void chooseTypeRace(int& racingType);

// Функция выбора действия (1. зарегистрировать транспорт)
VEHICLESLIBRARY_API void chooseAction(int& action);

// Функция выбора действия (1. зарегистрировать транспорт, 2. начать гонку)
VEHICLESLIBRARY_API void chooseAction(int step, int& action);

// Функция выбора длины дистанции
VEHICLESLIBRARY_API void chooseDistance(float& distance);

// Функция вывода зарегистрированных транспортных средств
VEHICLESLIBRARY_API void showRegisteredVehicles(int racingType, float distance, std::string registeredVehicles);

// Функция выбора номера транспортного средства для регистрации в гонке
VEHICLESLIBRARY_API int getNumberVehicle(int racingType, int& numberVehicle);

// Функция выбора транспортного средства в зависимости от введеного номера транспортного средства
VEHICLESLIBRARY_API DynamicVehicles::Vehicles chooseVehicle(
	int step,
	int numberVehicle,
	std::string& registeredVehicles,
	DynamicVehicles::Vehicles* vehiclesArray,
	int& i,
	float distance);

// Функция регистрации транспортного средства
VEHICLESLIBRARY_API void registerVehicle(
	int racingType,
	int step,
	int& numberVehicle,
	std::string& registeredVehicles,
	DynamicVehicles::Vehicles* vehiclesArray,
	int& i,
	float distance);

// Функция проверки повторной регистрации транспорта 
VEHICLESLIBRARY_API int checkVehiclesArray(DynamicVehicles::Vehicles vehicle, DynamicVehicles::Vehicles* vehiclesArray, int& i, std::string& registeredVehicles, int size = 7);

// Функция расчёта результата гонки
VEHICLESLIBRARY_API void resultRacing(int i, int& action, DynamicVehicles::Vehicles* vehiclesArray);

// Функция сортировки массива транспортных средств
VEHICLESLIBRARY_API void sortVehiclesArray(int i, DynamicVehicles::Vehicles* vehiclesArray);