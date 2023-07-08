//Исходный файл функций проекта

#include "Functions.h"
#include <limits>

// ______________________________выбор типа гонки_______________________________

void chooseTypeRace(int& racingType) {
	bool flag;
	do {
		std::cout << "1. Гонка для наземного транспорта\n";
		std::cout << "2. Гонка для воздушного транспорта\n";
		std::cout << "3. Гонка для наземного и воздушного транспорта\n";
		std::cout << "Виберите тип гонки: ";
		std::cin >> racingType;
		                                                                                   // удаление '\n' чтобы не возникало бесконечного цикла
		std::cin.clear();                                                                  // на случай, если предыдущий ввод завершился с ошибкой
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                //Функция класса istream Извлекает вводимые символы из списка и отбрасывает их  
		                                                                                   //до тех пор, пока один из них не сравняется с flag.
		flag = racingType != 1 && racingType != 2 && racingType != 3;
		if (flag) {
			std::cout << "Необходимо ввести значение из списка!\n";
		}
	} while (flag);
}
// ___________________выбор действия (1. зарегистрировать транспорт)________________

void chooseAction(int& action) {
	bool flag;
	do {
		std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства\n";
		std::cout << "1. Зарегистрировать транспорт\n";
		std::cout << "Выберите действие: ";
		std::cin >> action;
		                                                                                      // удаление '\n' чтобы не возникало бесконечного цикла
		std::cin.clear();                                                                     // на случай, если предыдущий ввод завершился с ошибкой

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		flag = action != 1;
		if (flag) {
			std::cout << "Необходимо ввести значение из списка!\n";
		}
	} while (flag);
}
// __________выбор действия (1. зарегистрировать транспорт, 2. начать гонку)___________

void chooseAction(int step, int& action) {

	bool flag;
	do {
		std::cout << "1. Зарегистрировать транспорт\n";
		std::cout << "2. Начать гонку\n";
		std::cout << "Выберите действие: ";
		std::cin >> action;

	
		std::cin.clear();

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		flag = action != 1 && action != 2;
		if (flag) {
			std::cout << "Необходимо ввести значение из списка!\n";
		}
	} while (flag);
}
// _______________________выбор длины дистанции______________________________________________

void chooseDistance(float& distance) {

	bool flag;
	do {
		std::cout << "Укажите длину дистанции (должна быть положительна): ";
		std::cin >> distance;

		flag = distance < 0;
		if (flag) {
			std::cout << "Длина дистанции должна быть положительна!\n";
		}
	} while (flag);
}
// ______вывод на экран зарегистрированных участников, типа гонки и дистанции_________________

void showRegisteredVehicles(int racingType, float distance, std::string registeredVehicles) {

	if (racingType == 1) {

		std::cout << "Гонка для наземного транспорта. Расстояние: " << distance << "\n";

		if (registeredVehicles.length() != 0) {

			std::cout << "Зарегистрированные транспортные средства: " + registeredVehicles + "\n";
		}
	}
	else if (racingType == 2) {

		std::cout << "Гонка для воздушного транспорта. Расстояние: " << distance << "\n";

		if (registeredVehicles.length() != 0) {

			std::cout << "Зарегистрированные транспортные средства: " + registeredVehicles + "\n";
		}
	}
	else {
		std::cout << "Гонка для наземного и воздушного транспорта. Расстояние: " << distance << "\n";

		if (registeredVehicles.length() != 0) {

			std::cout << "Зарегистрированные транспортные средства: " + registeredVehicles + "\n";
		}
	}
}
// _________выбор транспортного средства для регистрации в гонке___________________________________

int getNumberVehicle(int racingType, int& numberVehicle) {

	bool flag;
	do {
		std::cout << "1. Ботинки-вездеходы\n";
		std::cout << "2. Метла\n";
		std::cout << "3. Верблюд\n";
		std::cout << "4. Кентавр\n";
		std::cout << "5. Орёл\n";
		std::cout << "6. Верблюд-быстроход\n";
		std::cout << "7. Ковёр-самолёт\n";
		std::cout << "0. Закончить регистрацию\n";
		std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";

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
			std::cout << "Необходимо ввести значение из списка!\n";
		}

		if (racingType == 1 && (numberVehicle == 2 || numberVehicle == 5 || numberVehicle == 7))
		{
			std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
			return 1;
		}

		else if (racingType == 2 && (numberVehicle == 1 || numberVehicle == 3 || numberVehicle == 4 || numberVehicle == 6))
		{
			std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!\n";
			return 2;
		}

	} while (flag);
	return 0;
}

//___________выбор участника в зависимости от введеного номера транспортного средства________________

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
			std::cout << "Ботинки-вездеходы успешно зарегистрированы!\n";
			registeredVehicles += "Ботинки-вездеходы";
		}
		return *ptr_vehicle;
	}
	else if (numberVehicle == 2)
	{
		DynamicVehicles::Broom broom(distance);
		ptr_vehicle = &broom;

		if (checkVehiclesArray(*ptr_vehicle, vehiclesArray, i, registeredVehicles) == 0)
		{
			std::cout << "Метла успешно зарегистрирована!\n";
			registeredVehicles += "Метла";
		}
		return *ptr_vehicle;
	}
	else if (numberVehicle == 3)
	{
		DynamicVehicles::Camel camel(distance);
		ptr_vehicle = &camel;

		if (checkVehiclesArray(*ptr_vehicle, vehiclesArray, i, registeredVehicles) == 0)
		{
			std::cout << "Верблюд успешно зарегистрирован!\n";
			registeredVehicles += "Верблюд";
		}
		return *ptr_vehicle;
	}
	else if (numberVehicle == 4)
	{
		DynamicVehicles::Centaur centaur(distance);
		ptr_vehicle = &centaur;

		if (checkVehiclesArray(*ptr_vehicle, vehiclesArray, i, registeredVehicles) == 0)
		{
			std::cout << "Кентавр успешно зарегистрирован!\n";
			registeredVehicles += "Кентавр";
		}
		return *ptr_vehicle;
	}
	else if (numberVehicle == 5)
	{
		DynamicVehicles::Eagle eagle(distance);
		ptr_vehicle = &eagle;

		if (checkVehiclesArray(*ptr_vehicle, vehiclesArray, i, registeredVehicles) == 0)
		{
			std::cout << "Орёл успешно зарегистрирован!\n";
			registeredVehicles += "Орёл";
		}
		return *ptr_vehicle;
	}
	else if (numberVehicle == 6)
	{
		DynamicVehicles::CamelSpeedWalker camelSpeedWalker(distance);
		ptr_vehicle = &camelSpeedWalker;

		if (checkVehiclesArray(*ptr_vehicle, vehiclesArray, i, registeredVehicles) == 0)
		{
			std::cout << "Верблюд-быстроход успешно зарегистрирован!\n";
			registeredVehicles += "Верблюд-быстроход";
		}
		return *ptr_vehicle;
	}
	else if (numberVehicle == 7)
	{
		DynamicVehicles::CarpetPlane carpetPlane(distance);
		ptr_vehicle = &carpetPlane;

		if (checkVehiclesArray(*ptr_vehicle, vehiclesArray, i, registeredVehicles) == 0)
		{
			std::cout << "Ковёр-самолёт успешно зарегистрирован!\n";
			registeredVehicles += "Ковёр-самолёт";
		}
		return *ptr_vehicle;
	}

}
// _____________регистрация транспортного средства___________________________________________

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

	int checkRacingType = getNumberVehicle(racingType, numberVehicle);                           // Проверка типа вводимого транспортного средства    
	
	if (checkRacingType == 0 && numberVehicle != 0)
	{
		chooseVehicle(step, numberVehicle, registeredVehicles, vehiclesArray, i, distance);
	}
}

// _________________проверка повторной регистрации транспорта_____________________________

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
		std::cout << vehicle.getVehicleName() + " уже зарегистрирован!\n";
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

// _____________________расчёт результата гонки___________________________________

void resultRacing(int i, int& action, DynamicVehicles::Vehicles* vehiclesArray)
{
	bool flag;
	do {
		std::cout << "Результаты гонки:\n";

		sortVehiclesArray(i, vehiclesArray);

		std::cout << "\n";
		std::cout << "1. Провести ещё одну гонку\n";
		std::cout << "2. Выйти\n";
		std::cout << "Выберите действие: ";
		std::cin >> action;

		                                                                              // удаление '\n' чтобы не возникало бесконечного цикла
		std::cin.clear();                                                             // на случай, если предыдущий ввод завершился с ошибкой
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		flag = action != 1 && action != 2;

		if (flag) {
			std::cout << "Необходимо ввести значение из списка!\n";
		}
	} while (flag);
}

// _____________________сортировка массива транспортных средств_________________________

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

		std::cout << i + 1 << ". " << vehiclesArray[i].getVehicleName() + ". Время: " << vehiclesArray[i].getResultTime() << "\n";
}