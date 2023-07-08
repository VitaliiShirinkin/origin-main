
#include <iostream>
#include <Windows.h>
#include <string>

struct address
{
    std::string city;
    std::string street;
    int house_number;
    int apartment_number;
    int index;
};

void Console(address a) {
        std::cout << "Город: " << a.city << std::endl;
        std::cout << "Улица: " << a.street << std::endl;
        std::cout << "Номер дома: " << a.house_number << std::endl;
        std::cout << "Номер квартиры: " << a.apartment_number << std::endl;
        std::cout << "Индекс: " << a.index << std::endl;
        std::cout << std::endl;
    }

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    address a { "Москва", "Арбат", 12, 8, 123456};
    address b{ "Ижевск", "Пушкина", 59, 143, 953769};

    Console(a);
    Console(b);

}
