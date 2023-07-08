//Производный класс "Кентавр" от класса наземных ТС

#include "Centaur.h"

namespace DynamicVehicles {

	Centaur::Centaur(float distance_) {

		nameVehicle = "Кентавр";
		velocity = 15;
		timeBeforeRest = 8;
		restPeriod_1 = 2;
		distance = distance_;
		resultTime = calculateTime();
	}
	float Centaur::calculateTime() {

		auto timeWithoutRest = distance / velocity;
		int timeWithRest = round(timeWithoutRest / timeBeforeRest);

		if (timeWithRest == 0) {
			return timeWithoutRest;
		}
		else {
			return timeWithoutRest + (timeWithRest - 1) * restPeriod_1;
		}

	}
}