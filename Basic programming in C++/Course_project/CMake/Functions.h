//������������ ���� ������� �������

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


// ������� ������ ���� �����
VEHICLESLIBRARY_API void chooseTypeRace(int& racingType);

// ������� ������ �������� (1. ���������������� ���������)
VEHICLESLIBRARY_API void chooseAction(int& action);

// ������� ������ �������� (1. ���������������� ���������, 2. ������ �����)
VEHICLESLIBRARY_API void chooseAction(int step, int& action);

// ������� ������ ����� ���������
VEHICLESLIBRARY_API void chooseDistance(float& distance);

// ������� ������ ������������������ ������������ �������
VEHICLESLIBRARY_API void showRegisteredVehicles(int racingType, float distance, std::string registeredVehicles);

// ������� ������ ������ ������������� �������� ��� ����������� � �����
VEHICLESLIBRARY_API int getNumberVehicle(int racingType, int& numberVehicle);

// ������� ������ ������������� �������� � ����������� �� ��������� ������ ������������� ��������
VEHICLESLIBRARY_API DynamicVehicles::Vehicles chooseVehicle(
	int step,
	int numberVehicle,
	std::string& registeredVehicles,
	DynamicVehicles::Vehicles* vehiclesArray,
	int& i,
	float distance);

// ������� ����������� ������������� ��������
VEHICLESLIBRARY_API void registerVehicle(
	int racingType,
	int step,
	int& numberVehicle,
	std::string& registeredVehicles,
	DynamicVehicles::Vehicles* vehiclesArray,
	int& i,
	float distance);

// ������� �������� ��������� ����������� ���������� 
VEHICLESLIBRARY_API int checkVehiclesArray(DynamicVehicles::Vehicles vehicle, DynamicVehicles::Vehicles* vehiclesArray, int& i, std::string& registeredVehicles, int size = 7);

// ������� ������� ���������� �����
VEHICLESLIBRARY_API void resultRacing(int i, int& action, DynamicVehicles::Vehicles* vehiclesArray);

// ������� ���������� ������� ������������ �������
VEHICLESLIBRARY_API void sortVehiclesArray(int i, DynamicVehicles::Vehicles* vehiclesArray);