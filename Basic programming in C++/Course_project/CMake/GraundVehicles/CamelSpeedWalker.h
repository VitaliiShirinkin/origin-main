//����������� ����� "�������-���������" �� ������ �������� ��

#pragma once
#include "GraundVehicles.h"

namespace DynamicVehicles {

	class CamelSpeedWalker : public GraundVehicles {

	public:
		CamelSpeedWalker(float distance_);
		VEHICLESLIBRARY_API float calculateTime() override;
	};
}