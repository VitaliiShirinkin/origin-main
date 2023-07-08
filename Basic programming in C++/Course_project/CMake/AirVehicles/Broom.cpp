//Производный класс "Метла" от класса воздушных ТС

#include "Broom.h"

namespace DynamicVehicles {

	Broom::Broom(float distance_) {

		nameVehicle = "Метла";
		velocity = 20;

		distanceReductionFactor = 1 - floor(distance_ / 1000) / 100;      //коэффициент уменьшения расстояния.Функция floor возвращает максимально возможное целое значение, 
		                                                                  //которое равно значению или меньше этого.
		distance = distanceReductionFactor * distance_;                   //расстояние
		resultTime = calculateTime();                                     //Расчёт времени заезда

	}
}