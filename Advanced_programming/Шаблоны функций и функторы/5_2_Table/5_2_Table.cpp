#include <iostream>
#include "5_2_Table.h"



int main()
{
	auto test = Table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0];

	return 0;
}