//�������� ���� ������� �������

#include "Functions.h"
#include <limits>

// ______________________________����� ���� �����_______________________________

void chooseTypeRace(int& racingType) {
	bool flag;
	do {
		std::cout << "1. ����� ��� ��������� ����������\n";
		std::cout << "2. ����� ��� ���������� ����������\n";
		std::cout << "3. ����� ��� ��������� � ���������� ����������\n";
		std::cout << "�������� ��� �����: ";
		std::cin >> racingType;
		                                                                                   // �������� '\n' ����� �� ��������� ������������ �����
		std::cin.clear();                                                                  // �� ������, ���� ���������� ���� ���������� � �������
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                //������� ������ istream ��������� �������� ������� �� ������ � ����������� ��  
		                                                                                   //�� ��� ���, ���� ���� �� ��� �� ���������� � flag.
		flag = racingType != 1 && racingType != 2 && racingType != 3;
		if (flag) {
			std::cout << "���������� ������ �������� �� ������!\n";
		}
	} while (flag);
}
// ___________________����� �������� (1. ���������������� ���������)________________

void chooseAction(int& action) {
	bool flag;
	do {
		std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������\n";
		std::cout << "1. ���������������� ���������\n";
		std::cout << "�������� ��������: ";
		std::cin >> action;
		                                                                                      // �������� '\n' ����� �� ��������� ������������ �����
		std::cin.clear();                                                                     // �� ������, ���� ���������� ���� ���������� � �������

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		flag = action != 1;
		if (flag) {
			std::cout << "���������� ������ �������� �� ������!\n";
		}
	} while (flag);
}
// __________����� �������� (1. ���������������� ���������, 2. ������ �����)___________

void chooseAction(int step, int& action) {

	bool flag;
	do {
		std::cout << "1. ���������������� ���������\n";
		std::cout << "2. ������ �����\n";
		std::cout << "�������� ��������: ";
		std::cin >> action;

	
		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		flag = action != 1 && action != 2;
		if (flag) {
			std::cout << "���������� ������ �������� �� ������!\n";
		}
	} while (flag);
}
// _______________________����� ����� ���������______________________________________________

void chooseDistance(float& distance) {

	bool flag;
	do {
		std::cout << "������� ����� ��������� (������ ���� ������������): ";
		std::cin >> distance;

		flag = distance < 0;
		if (flag) {
			std::cout << "����� ��������� ������ ���� ������������!\n";
		}
	} while (flag);
}
// ______����� �� ����� ������������������ ����������, ���� ����� � ���������_________________

void showRegisteredVehicles(int racingType, float distance, std::string registeredVehicles) {

	if (racingType == 1) {

		std::cout << "����� ��� ��������� ����������. ����������: " << distance << "\n";

		if (registeredVehicles.length() != 0) {

			std::cout << "������������������ ������������ ��������: " + registeredVehicles + "\n";
		}
	}
	else if (racingType == 2) {

		std::cout << "����� ��� ���������� ����������. ����������: " << distance << "\n";

		if (registeredVehicles.length() != 0) {

			std::cout << "������������������ ������������ ��������: " + registeredVehicles + "\n";
		}
	}
	else {
		std::cout << "����� ��� ��������� � ���������� ����������. ����������: " << distance << "\n";

		if (registeredVehicles.length() != 0) {

			std::cout << "������������������ ������������ ��������: " + registeredVehicles + "\n";
		}
	}
}
// _________����� ������������� �������� ��� ����������� � �����___________________________________

int getNumberVehicle(int racingType, int& numberVehicle) {

	bool flag;
	do {
		std::cout << "1. �������-���������\n";
		std::cout << "2. �����\n";
		std::cout << "3. �������\n";
		std::cout << "4. �������\n";
		std::cout << "5. ���\n";
		std::cout << "6. �������-���������\n";
		std::cout << "7. ����-������\n";
		std::cout << "0. ��������� �����������\n";
		std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";

		std::cin >> numberVehicle;

		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		flag = numberVehicle != 0 &&
			   numberVehicle != 1 &&
			   numberVehicle != 2 &&
			   numberVehicle != 3 &&
			   numberVehicle != 4 &&
			   numberVehicle != 5 &&
			   numberVehicle != 6 &&
			   numberVehicle != 7;

		if (flag)
		{
			std::cout << "���������� ������ �������� �� ������!\n";
		}

		if (racingType == 1 && (numberVehicle == 2 || numberVehicle == 5 || numberVehicle == 7))
		{
			std::cout << "������� ���������������� ������������ ��� ������������� ��������!\n";
			return 1;
		}

		else if (racingType == 2 && (numberVehicle == 1 || numberVehicle == 3 || numberVehicle == 4 || numberVehicle == 6))
		{
			std::cout << "������� ���������������� ������������ ��� ������������� ��������!\n";
			return 2;
		}

	} while (flag);
	return 0;
}

//___________����� ��������� � ����������� �� ��������� ������ ������������� ��������________________

DynamicVehicles::Vehicles chooseVehicle(
	int step,
	int numberVehicle,
	std::string& registeredVehicles,
	DynamicVehicles::Vehicles* vehiclesArray,
	int& i,
	float distance)
{
	DynamicVehicles::Vehicles* ptr_vehicle;

	if (numberVehicle == 1)
	{
		DynamicVehicles::BootsAllTerrain bootsAllTerrain(distance);

		ptr_vehicle = &bootsAllTerrain;

		if (checkVehiclesArray(*ptr_vehicle, vehiclesArray, i, registeredVehicles) == 0)
		{
			std::cout << "�������-��������� ������� ����������������!\n";
			registeredVehicles += "�������-���������";
		}
		return *ptr_vehicle;
	}
	else if (numberVehicle == 2)
	{
		DynamicVehicles::Broom broom(distance);
		ptr_vehicle = &broom;

		if (checkVehiclesArray(*ptr_vehicle, vehiclesArray, i, registeredVehicles) == 0)
		{
			std::cout << "����� ������� ����������������!\n";
			registeredVehicles += "�����";
		}
		return *ptr_vehicle;
	}
	else if (numberVehicle == 3)
	{
		DynamicVehicles::Camel camel(distance);
		ptr_vehicle = &camel;

		if (checkVehiclesArray(*ptr_vehicle, vehiclesArray, i, registeredVehicles) == 0)
		{
			std::cout << "������� ������� ���������������!\n";
			registeredVehicles += "�������";
		}
		return *ptr_vehicle;
	}
	else if (numberVehicle == 4)
	{
		DynamicVehicles::Centaur centaur(distance);
		ptr_vehicle = &centaur;

		if (checkVehiclesArray(*ptr_vehicle, vehiclesArray, i, registeredVehicles) == 0)
		{
			std::cout << "������� ������� ���������������!\n";
			registeredVehicles += "�������";
		}
		return *ptr_vehicle;
	}
	else if (numberVehicle == 5)
	{
		DynamicVehicles::Eagle eagle(distance);
		ptr_vehicle = &eagle;

		if (checkVehiclesArray(*ptr_vehicle, vehiclesArray, i, registeredVehicles) == 0)
		{
			std::cout << "��� ������� ���������������!\n";
			registeredVehicles += "���";
		}
		return *ptr_vehicle;
	}
	else if (numberVehicle == 6)
	{
		DynamicVehicles::CamelSpeedWalker camelSpeedWalker(distance);
		ptr_vehicle = &camelSpeedWalker;

		if (checkVehiclesArray(*ptr_vehicle, vehiclesArray, i, registeredVehicles) == 0)
		{
			std::cout << "�������-��������� ������� ���������������!\n";
			registeredVehicles += "�������-���������";
		}
		return *ptr_vehicle;
	}
	else if (numberVehicle == 7)
	{
		DynamicVehicles::CarpetPlane carpetPlane(distance);
		ptr_vehicle = &carpetPlane;

		if (checkVehiclesArray(*ptr_vehicle, vehiclesArray, i, registeredVehicles) == 0)
		{
			std::cout << "����-������ ������� ���������������!\n";
			registeredVehicles += "����-������";
		}
		return *ptr_vehicle;
	}

}
// _____________����������� ������������� ��������___________________________________________

void registerVehicle
	(int racingType,
	int step,
	int& numberVehicle,
	std::string& registeredVehicles,
	DynamicVehicles::Vehicles* vehiclesArray,
	int& i,
	float distance)
{
	showRegisteredVehicles(racingType, distance, registeredVehicles);

	int checkRacingType = getNumberVehicle(racingType, numberVehicle);                           // �������� ���� ��������� ������������� ��������    
	
	if (checkRacingType == 0 && numberVehicle != 0)
	{
		chooseVehicle(step, numberVehicle, registeredVehicles, vehiclesArray, i, distance);
	}
}

// _________________�������� ��������� ����������� ����������_____________________________

	int checkVehiclesArray
	    (DynamicVehicles::Vehicles vehicle,
		DynamicVehicles::Vehicles* vehiclesArray,
		int& i,
		std::string& registeredVehicles,
		int size)
{
	int check = 0;
	for (int i = 0; i < size; i++)
	{
		if (vehicle == vehiclesArray[i])
		{
			check = 1;
		}
	}
	if (check == 1)
	{
		std::cout << vehicle.getVehicleName() + " ��� ���������������!\n";
	}
	else
	{
		vehiclesArray[i] = vehicle;
		if (i != 0)
		{
			registeredVehicles += ", ";
		}
		i++;
	}
	return check;
}

// _____________________������ ���������� �����___________________________________

void resultRacing(int i, int& action, DynamicVehicles::Vehicles* vehiclesArray)
{
	bool flag;
	do {
		std::cout << "���������� �����:\n";

		sortVehiclesArray(i, vehiclesArray);

		std::cout << "\n";
		std::cout << "1. �������� ��� ���� �����\n";
		std::cout << "2. �����\n";
		std::cout << "�������� ��������: ";
		std::cin >> action;

		                                                                              // �������� '\n' ����� �� ��������� ������������ �����
		std::cin.clear();                                                             // �� ������, ���� ���������� ���� ���������� � �������
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		flag = action != 1 && action != 2;

		if (flag) {
			std::cout << "���������� ������ �������� �� ������!\n";
		}
	} while (flag);
}

// _____________________���������� ������� ������������ �������_________________________

void sortVehiclesArray(int i, DynamicVehicles::Vehicles* vehiclesArray)
{
	int lengthVehiclesArray = i;
	DynamicVehicles::Vehicles buf;

	for (int i = 0; i < lengthVehiclesArray; i++)
	{
		for (int j = 0; j < lengthVehiclesArray; j++)
		{
			if (vehiclesArray[i].getResultTime() < vehiclesArray[j].getResultTime())
			{
				buf = vehiclesArray[j];
				vehiclesArray[j] = vehiclesArray[i];
				vehiclesArray[i] = buf;
			}
		}
	}
	for (int i = 0; i < lengthVehiclesArray; i++)

		std::cout << i + 1 << ". " << vehiclesArray[i].getVehicleName() + ". �����: " << vehiclesArray[i].getResultTime() << "\n";
}