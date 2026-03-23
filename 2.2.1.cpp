#include <iostream>

int Fibonacci(int* arr, int n);

int main() 
{
	int size{ 25 };
	int* arrayFibo = new int[size];
	std::cout << "Fibonacci: ";

	for (int i{ 0 }; i < size; ++i)
	{
		arrayFibo[i] = -1;
	}

	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << Fibonacci(arrayFibo, i) << ' ';
	}

	std::cout << "\n\nFibonacci after add to array: ";
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << Fibonacci(arrayFibo, i) << ' ';
	}
	
	delete[] arrayFibo;
	return EXIT_SUCCESS;
}

int Fibonacci(int* arr, int n)
{
	if (n <= 1) { return n; }

	if (arr[n] != -1) { return arr[n]; }
    
	arr[n] = Fibonacci(arr, n - 1) + Fibonacci(arr, n - 2);
	return arr[n];
}
