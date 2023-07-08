// 2_1Fibonacci_numbers_again.cpp : 
//Программа, которая реализует рекурсивный подсчёт чисел Фибоначчи.

//Сложность алгоритма по скорости О(2^n). Сложность по памяти О(1)

#include <iostream>
#include <cassert>

uint64_t fib_recursive(int n) {

	assert (n >= 0);

	if (n == 0 or n == 1) {
		return n;
	}
	else
	{
		return fib_recursive(n - 1) + fib_recursive(n - 2);
	}

}

int main() {

	for (int n = 0; n <= 15; n++) {

		std::cout << n << '\t' << fib_recursive(n) << '\n';
	}
	return 0;
}

