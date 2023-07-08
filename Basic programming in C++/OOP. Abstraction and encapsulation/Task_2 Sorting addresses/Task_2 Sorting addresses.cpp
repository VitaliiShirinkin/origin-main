
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <cstring>

class Address //Создаем класс Адресс с методами и описанием экземпляров
{
public:
    Address(std::string name_city, std::string name_street, int number_house, int apartment_number) {//Конструктор-метод
        this->name_city = name_city;
        this->name_street = name_street;
        this->number_house = number_house;
        this->apartment_number = apartment_number;
    };
    // Метод создания строки полного адреса для вывода
    std::string get_output_address()
    {
        address = name_city + ", " + name_street + ", " + std::to_string(number_house)
            + ", " + std::to_string(apartment_number);
        return address;
    };

private:
    std::string name_city;
    std::string name_street;
    int number_house = 0;
    int apartment_number = 0;
    std::string address;
};

std::string* create_arr_str(const int sum) //Функция создания текстового динамического массива
{
    std::string* arr_str = new std::string[sum]{};

    return arr_str;
}

void printArr(std::string* arrAdd, const int sum) //Функция печати массива в файл
{
    std::ofstream fOut("out.txt");

    fOut << sum << std::endl;

    for (int i = 0; i < sum; ++i)
    {
        fOut << arrAdd[i] << std::endl;
    }
    fOut.close();
};

void Sort_add(std::string* arrAdd, const int sum)//Функция сортировки пузырьком
{
    bool swapped = false;
    do {
        swapped = false;
        std::string tmp;

        for (int i = sum - 1; i > 0; --i)
        {
            if (arrAdd[i - 1] > arrAdd[i])
            {
                tmp = arrAdd[i];
                arrAdd[i] = arrAdd[i - 1];
                arrAdd[i - 1] = tmp;
                swapped = true;
            }
        }
    } while (swapped);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream fin("in.txt");

    int sum = 0;
    std::string name_city = {};
    std::string name_street = {};
    int number_house = 0;
    int apartment_number = 0;

    fin >> sum; //Записываем кол-во адресов в переменную 

    std::string* arrAdd = create_arr_str(sum); //Cоздаем динамический массив для объектов класса Adress


    for (int i = 0; i < sum; i++) //Считываем адрес
    {
        fin >> name_city >> name_street >> number_house >> apartment_number;
        Address address(name_city, name_street, number_house, apartment_number);

        arrAdd[i] = address.get_output_address();
    };

    fin.close(); //Закрываем файл in.txt

    Sort_add(arrAdd, sum);
    printArr(arrAdd, sum);
    delete[]arrAdd;

}
