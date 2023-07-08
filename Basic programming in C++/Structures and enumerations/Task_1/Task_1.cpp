#include <iostream>
//#include <Windows.h>

enum class mounths{january = 1, february, march, april, may, june, july, august, september, october, november, december};

int main()
{
    system("chcp 1251 > nul");
    int num=0;
    mounths nm = static_cast<mounths>(num);

    do
    {
        std::cout << "Введите номер месяца: ";
        std::cin >> num;

        if (num < 0 || num>12)
        {
            std::cout << "Неправильный номер!" << std::endl;

        }
        else if (num == 0) {
            std::cout << "До свидания" << std::endl;
        }
        else
        {
            switch (num)
            {
            case 1: std::cout << "Январь" << std::endl;
                break;
            case 2: std::cout << "Февраль" << std::endl;
                break;
            case 3: std::cout << "Март" << std::endl;
                break;
            case 4: std::cout << "Апрель" << std::endl;
                break;
            case 5: std::cout << "Май" << std::endl;
                break;
            case 6: std::cout << "Июнь" << std::endl;
                break;
            case 7: std::cout << "Июль" << std::endl;
                break;
            case 8: std::cout << "Август" << std::endl;
                break;
            case 9: std::cout << "Сентябрь" << std::endl;
                break;
            case 10: std::cout << "Октябрь" << std::endl;
                break;
            case 11: std::cout << "Ноябрь" << std::endl;
                break;
            case 12: std::cout << "Декабрь" << std::endl;
                break;
            }
        }
    } while (num != 0);

    return 0;
}

