//Производный класс "Орёл" от класса воздушных ТС

#include "Eagle.h"

namespace DynamicVehicles {

	Eagle::Eagle(float distance_) {

		nameVehicle = "Орёл";
		velocity = 8;
		distanceReductionFactor = 0.94f;

		distance = distanceReductionFactor * distance_;
		resultTime = calculateTime();
	}
}