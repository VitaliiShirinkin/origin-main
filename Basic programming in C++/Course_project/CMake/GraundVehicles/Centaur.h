//Производный класс "Кентавр" от класса наземных ТС

#pragma once
#include "GraundVehicles.h"

namespace DynamicVehicles {

	class Centaur : public GraundVehicles {

	public:
		Centaur(float distance_);
		VEHICLESLIBRARY_API float calculateTime() override;
	};
}