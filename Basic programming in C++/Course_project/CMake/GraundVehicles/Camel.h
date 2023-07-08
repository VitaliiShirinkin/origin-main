//Производный класс от класса наземных ТС

#pragma once
#include "GraundVehicles.h"

namespace DynamicVehicles {

	class Camel : public DynamicVehicles::GraundVehicles {

	public:
		Camel(float distance_);
		VEHICLESLIBRARY_API float calculateTime() override;
	};


}