// 5_1_Template.cpp :

#include <iostream>
#include <vector>
#include <windows.h>
#include "template.h"

void print (std::vector<int>vec)
{
    for (int i : vec) {
        std::cout << i<< " ";
    }
    std::cout<<std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

int n =4;
std::cout << "[IN]: " << n << "\n";
std::cout << "[OUT]: " << power(n) << "\n";

std::vector<int>vec {-1, 4, 8};
    std::cout << "[IN]: ";
    print (vec);
    std::cout << "[OUT]: ";
    Power (vec);
    print (vec);
    return 0;
}




