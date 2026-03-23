#include <iostream>

int Fibonacchi(int n);

int main() 
{
	std::cout << "Fibonacchi: ";
	for (int i{ 0 }; i < 20; ++i)
	{
		std::cout << Fibonacchi(i) << ' ';
	}

	return EXIT_SUCCESS;
}

int Fibonacchi(int n)
{
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	else return Fibonacchi(n - 1) + Fibonacchi(n - 2);
}
