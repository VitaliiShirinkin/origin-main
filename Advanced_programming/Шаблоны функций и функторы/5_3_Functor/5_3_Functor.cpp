// 5_3_Functor.cpp : Задача 3. Счетчик чисел
//https://github.com/netology-code/cppl-homeworks/tree/main/05/03

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

class summ_funktor
{
	int counter;
	int summ;
public:
	summ_funktor() : summ{ 0 }, counter{ 0 } {}

	void operator() (int n)
	{
		if (n % 3 == 0)
		{
			counter++;
			summ += n;
		}

	}

	int getSum()
	{
		return summ;
	}
	int getcount()
	{
		return counter;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector <int> vec{ 4, 1, 3, 6, 25, 54 };

	summ_funktor sf;
	std::for_each(vec.begin(), vec.end(), sf);
	std::cout << "[IN]: ";
	auto print = [](const int& n) {std::cout << " " << n; };
	std::for_each(vec.begin(), vec.end(), print);
	std::cout << std::endl;

	sf = std::for_each(vec.begin(), vec.end(), sf);
	std::cout << "[OUT]:  getcount() = " << sf.getcount() << "\n";
	std::cout << "[OUT]:  getSum() = " << sf.getSum() << "\n";
	return 0;
}


