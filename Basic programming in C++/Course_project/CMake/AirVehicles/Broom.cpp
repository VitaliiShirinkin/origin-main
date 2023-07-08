//����������� ����� "�����" �� ������ ��������� ��

#include "Broom.h"

namespace DynamicVehicles {

	Broom::Broom(float distance_) {

		nameVehicle = "�����";
		velocity = 20;

		distanceReductionFactor = 1 - floor(distance_ / 1000) / 100;      //����������� ���������� ����������.������� floor ���������� ����������� ��������� ����� ��������, 
		                                                                  //������� ����� �������� ��� ������ �����.
		distance = distanceReductionFactor * distance_;                   //����������
		resultTime = calculateTime();                                     //������ ������� ������

	}
}