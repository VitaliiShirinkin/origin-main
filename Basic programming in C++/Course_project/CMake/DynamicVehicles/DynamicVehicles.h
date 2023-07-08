// ������������ ����� ������������ �������

#pragma once
#include <iostream>

#ifdef VehiclesLibraryDynamic_EXPORTS 
#define VEHICLESLIBRARY_API __declspec(dllexport)
#else
#ifdef VEHICLESLIBRARYDYNAMIC_EXPORTS
#define VEHICLESLIBRARY_API __declspec(dllexport)
#else
#define VEHICLESLIBRARY_API __declspec(dllimport)
#endif
#endif

// ������������ ��� ������������ ���������� ��
namespace DynamicVehicles
{
	
	class Vehicles                                                                                  // ������������ ����� ������������ �������
	{                                                                                               
	public:
		VEHICLESLIBRARY_API friend std::ostream& operator<<(std::ostream& left, Vehicles& right);   //��� ���������� ��������� ������.
		                                                                                            //������� ��������� ��� ���������: ������ �� ������� ���� ostream
		                                                                                            //ostream & ��� �������� (���������� ������ �� ������ ���� ostream)
		                                                                                            //operator<< �������� ����� ��� ���������� ���������
		VEHICLESLIBRARY_API bool operator==(Vehicles& right);                                       // ���������� ��������� "�����".
		VEHICLESLIBRARY_API std::string getVehicleName();
		VEHICLESLIBRARY_API float getVelocity();
		VEHICLESLIBRARY_API float getResultTime();
	protected:
		std::string nameVehicle;
		float velocity;                                                                              // �������� ������������� ��������
		float distance;                                                                              // ����� ��������� �����
		VEHICLESLIBRARY_API virtual float calculateTime();                                           // ����������� ����� ������� ������� ������
		float resultTime = calculateTime();                                                          // ����� ������
	};
}
