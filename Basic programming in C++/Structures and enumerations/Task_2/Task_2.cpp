
#include <iostream>
#include <Windows.h>
#include <string>

struct requisites
{
    int account_number;
    std::string name_owner;
    double balance;
};

void change_balance(requisites* sum) {
    std::cout << "Введите новый баланс: ";
    std::cin >> sum->balance;
    std::cout << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

 
    int account;
    std::string name;
    double sum;
    std::cout << "Введите номер счёта: ";
    std::cin >> account; std::cout << std::endl;

    std::cout << "Введите имя владельца: ";
    std::cin >> name; std::cout << std::endl;

    std::cout << "Введите баланс: ";
    std::cin >> sum; std::cout << std::endl;
;
    requisites pers;
    pers.account_number = account;
    pers.name_owner = name;
    pers.balance = sum;

  
    change_balance(&pers);

    std::cout << "Ваш счет: " << pers.account_number << ", " << pers.name_owner << ", " << pers.balance;
    system("pause");

}
