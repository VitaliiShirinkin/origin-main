//Производный класс "Ботинки-вездеходы" от класса наземных ТС

#pragma once
#include "GraundVehicles.h"

namespace DynamicVehicles {

	class BootsAllTerrain : public GraundVehicles {

	public:
		BootsAllTerrain(float distance_);
		VEHICLESLIBRARY_API float calculateTime() override;
	};
}