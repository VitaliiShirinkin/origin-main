//Производный класс "Ковёр-самолёт" от класса воздушных ТС

#pragma once
#include "AirVehicles.h"

namespace DynamicVehicles {

	class CarpetPlane : public AirVehicles {

	public:
		CarpetPlane(float distance_);
	};
}