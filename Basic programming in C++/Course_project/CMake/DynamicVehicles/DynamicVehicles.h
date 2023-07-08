// Родительский класс транспортных средств

#pragma once
#include <iostream>

#ifdef VehiclesLibraryDynamic_EXPORTS 
#define VEHICLESLIBRARY_API __declspec(dllexport)
#else
#ifdef VEHICLESLIBRARYDYNAMIC_EXPORTS
#define VEHICLESLIBRARY_API __declspec(dllexport)
#else
#define VEHICLESLIBRARY_API __declspec(dllimport)
#endif
#endif

// Пространство имён динамической библиотеки ТС
namespace DynamicVehicles
{
	
	class Vehicles                                                                                  // Родительский класс транспортных средств
	{                                                                                               
	public:
		VEHICLESLIBRARY_API friend std::ostream& operator<<(std::ostream& left, Vehicles& right);   //это перегрузка оператора вывода.
		                                                                                            //Функция принимает два параметра: ссылки на объекты типа ostream
		                                                                                            //ostream & тип возврата (возвращает ссылку на объект типа ostream)
		                                                                                            //operator<< ключевое слово для перегрузки оператора
		VEHICLESLIBRARY_API bool operator==(Vehicles& right);                                       // перегрузка оператора "равно".
		VEHICLESLIBRARY_API std::string getVehicleName();
		VEHICLESLIBRARY_API float getVelocity();
		VEHICLESLIBRARY_API float getResultTime();
	protected:
		std::string nameVehicle;
		float velocity;                                                                              // Скорость транспортного средства
		float distance;                                                                              // Длина дистанции гонки
		VEHICLESLIBRARY_API virtual float calculateTime();                                           // Виртуальный метод расчёта времени заезда
		float resultTime = calculateTime();                                                          // Время заезда
	};
}
