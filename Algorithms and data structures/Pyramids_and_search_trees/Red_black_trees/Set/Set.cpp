// Set.cpp : Красно-черные деревья
//В консоли вводятся слова, затем ищется из перечня слово

#include <iostream>
#include <set>
#include <string>
#include <Windows.h>

void set_example()
{
    std::set<std::string> words;//множество слов
    std::string word;

    getline(std::cin, word);
    while (word != "") {
        words.insert(word);//вставка слов в перечень
        getline(std::cin, word);
    }

    for (auto& word : words) {//распечатка перечня слов с помощью цикла по алфавиту
        std::cout << word << " ";
    }
    std::cout << std::endl;

    std::cout << "Введите ключ для поиска в наборе: ";
    std::cin >> word;

    if (words.find(word) != words.end()) {//поиск слов по ключу, пока слова не закончились
        std::cout << "Найдено!\n";
    }
    else {
        std::cout << "Не найдено...\n";
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    set_example();
    return 0;
}