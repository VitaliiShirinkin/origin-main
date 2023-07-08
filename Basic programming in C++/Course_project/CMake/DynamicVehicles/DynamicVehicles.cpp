#include "DynamicVehicles.h"

namespace DynamicVehicles
{
	float Vehicles::calculateTime()                                  // Метод расчёта времени заезда
	{                                
		return distance / velocity;
	}

	std::ostream& operator<<(std::ostream& left, Vehicles& right)    //Дружественная функция перегрузка оператора вывода.
	{  
		left << right.resultTime;
		return left;
	}

	bool Vehicles::operator==(Vehicles & right)                      //Метод перегрузки оператора равно.
	{                    
		if (nameVehicle == right.nameVehicle)
		{
			return true;
		}
		else
		{
			return false;
		}	
	}

	std::string Vehicles::getVehicleName()                           //Метод прочтения поля имени и возврат
	{
		return nameVehicle;
	}
	float Vehicles::getVelocity()                                    //Метод прочтения поля скорости и возврат
	{
		return velocity;
	}
	float Vehicles::getResultTime()                                  //Метод прочтения поля расчета времени заезда и возврат
	{
		return resultTime;
	}
}