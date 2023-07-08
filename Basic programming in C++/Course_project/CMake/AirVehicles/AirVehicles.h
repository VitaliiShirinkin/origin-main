#pragma once
#include "../DynamicVehicles/DynamicVehicles.h"

namespace DynamicVehicles {
	
	class AirVehicles : public Vehicles {       // Родительский класс воздушных транспортных средств (производный от класса ТС) 

	protected:
		float distanceReductionFactor;          // Коэффициент сокращения расстояния
	};
}