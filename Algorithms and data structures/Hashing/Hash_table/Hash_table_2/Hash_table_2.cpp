//Хеш-таблица(перемешивание)
//Ввод перечня слов, создание хеш-таблицы и вывод

#include <iostream>
#include <unordered_set>
#include <string>
#include <Windows.h>

void set_example()
{
    std::unordered_set<std::string> words;//контейнер для хеш-таблицы
    std::string word;

    getline(std::cin, word);
    while (word != "") {
        words.insert(word);//вставка слов в виде перечня через enter
        getline(std::cin, word);
    }

    for (auto& word : words) {
        std::cout << word << '\t';
    }
    std::cout << std::endl;

    std::cout << "Введите ключ для поиска: ";
    std::cin >> word;

    if (words.find(word) != words.end()) {//поиск искомого слова по ключу
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