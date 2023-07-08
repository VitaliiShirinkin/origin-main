// ����������� ����� �� ������ ������������ �������

#pragma once
#include "../DynamicVehicles/DynamicVehicles.h"

namespace DynamicVehicles {
	
	class GraundVehicles : public Vehicles {               // ������������ ����� �������� ������������ �������
	
	protected:
		float timeBeforeRest;                              // ����� �� ������
		float restPeriod_1;                                // ����� ������ 1
		float restPeriod_2;                                // ����� ������ 2
		float restPeriod_3;                                // ����� ������ 3
	};
}