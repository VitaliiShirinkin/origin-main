//Производный класс "Ботинки-вездеходы" от класса наземных ТС

#include "BootsAllTerrain.h"

namespace DynamicVehicles {
	BootsAllTerrain::BootsAllTerrain(float distance_) {

		nameVehicle = "Ботинки-вездеходы";
		velocity = 6;
		timeBeforeRest = 60;
		restPeriod_1 = 10;
		restPeriod_2 = 5;
		distance = distance_;
		resultTime = calculateTime();
	}
	float BootsAllTerrain::calculateTime() {

		auto timeWithoutRest = distance / velocity;                                        //Время без отдыха
		int timeWithRest = round(timeWithoutRest / timeBeforeRest);

		if (timeWithRest == 0) {
			return timeWithoutRest;
		}
		else if (timeWithRest == 1) {
			return timeWithoutRest + restPeriod_1;
		}
		else if (timeWithRest % 2 == 0) {
			return timeWithoutRest + restPeriod_1 + (timeWithRest - 1) * restPeriod_2;
		}
		else {
			return timeWithoutRest + restPeriod_1 + (timeWithRest - 2) * restPeriod_2;
		}
	}

}