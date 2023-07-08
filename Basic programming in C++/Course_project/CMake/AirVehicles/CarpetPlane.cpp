//Производный класс "Ковёр-самолёт" от класса воздушных ТС

#include "CarpetPlane.h"

namespace DynamicVehicles {

	CarpetPlane::CarpetPlane(float distance_)
	{

		nameVehicle = "Ковёр-самолёт";
		velocity = 10;

		if (distance_ < 1000)
		{
			distanceReductionFactor = 1;
		}
		else if (distance_ >= 1000 && distance_ < 5000)
		{
			distanceReductionFactor = 0.97f;
		}
		else if (distance_ >= 5000 && distance_ < 10000)
		{
			distanceReductionFactor = 0.9f;
		}
		else
		{
			distanceReductionFactor = 0.95f;
		}
		distance = distanceReductionFactor * distance_;
		resultTime = calculateTime();
	}
}
