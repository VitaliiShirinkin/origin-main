// 2.2Accelerating_Fibonacci.cpp : 
//Программа применения динамического программирования к рекурсии.

//Сложность алгоритма по скорости О(n). Сложность по памяти О(n).

#include <iostream>
#include <algorithm>

int dp[50];

int fib(int n)
{
	if (n <= 1)
		return n;

	// временные переменные для хранения
	// значения fib(n-1) и fib(n-2)
	int first, second;

	if (dp[n - 1] != -1)
		first = dp[n - 1];
	else
		first = fib(n - 1);

	if (dp[n - 2] != -1)
		second = dp[n - 2];
	else
		second = fib(n - 2);

	// запоминание (memoization) 
	return dp[n] = first + second;
}

int main()
{

	//инициализация массива dp как - 1
 std::fill(std::begin(dp),  std::end(dp), -1); 

	for (int n = 0; n <= 40; ++n) {
		
	 std::cout << n << '\t' << fib(n) << '\n';
    }
	return 0;

}


//uint64_t fib_dynamic(int n)
//{
//    uint64_t result;
//    uint64_t* fib = new uint64_t[n + 1];
//    fib[0] = 0;
//    fib[1] = 1;
//    for (int i = 2; i <= n; i++) {
//        fib[i] = fib[i - 1] + fib[i - 2];
//    }
//
//    result = fib[n];
// 
//    delete[] fib;
//    return result;
//}
//
//int main()
//{
//    for(int n = 0; n <= 15; n++){
//
//        std::cout << n << '\t' << fib_dynamic(n) << '\n';
//    }
//    return 0;
//}

