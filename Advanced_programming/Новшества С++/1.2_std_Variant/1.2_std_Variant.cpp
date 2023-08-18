// 1.2_std_Variant.cpp : Задача 2. std::variant
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <variant>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}



int main()
{
	auto tmp = get_variant();
	if (std::holds_alternative<int>(tmp))
	{
		std::cout << std::get<int>(tmp) * 2 << '\n';
	}
	else if(std::holds_alternative<std::string>(tmp))
	{
		std::cout << std::get<std::string>(tmp) << '\n';
	}
	else if (std::holds_alternative<std::vector<int>>(tmp))
	{
		for (const auto &i : std::get<std::vector<int>>(tmp))
		{
			std::cout << i << ' ';
		}
		std::cout << std::endl;
	}

    return 0;
}

