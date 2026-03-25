#include <iostream>

void count_sort(int* arr, int size);
void printArr(int* arr, int size);

int main()
{
	int arr1[]{ 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
	int size1{ sizeof(arr1) / sizeof(arr1[0])};

	std::cout << "Massive #1 before sort: ";
	printArr(arr1, size1);

	std::cout << "Massive #1 after sort: ";
	count_sort(arr1, size1);
	printArr(arr1, size1);

	int arr2[]{ 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
	int size2{ sizeof(arr2) / sizeof(arr2[0]) };

	std::cout << "\nMassive #2 before sort: ";
	printArr(arr2, size2);

	std::cout << "Massive #2 after sort: ";
	count_sort(arr2, size2);
	printArr(arr2, size2);

	int arr3[]{ 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 
		14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10, };
	int size3{ sizeof(arr3) / sizeof(arr3[0]) };

	std::cout << "\nMassive #3 before sort: ";
	printArr(arr3, size3);

	std::cout << "Massive #3 after sort: ";
	count_sort(arr3, size3);
	printArr(arr3, size3);
	
	return EXIT_SUCCESS;
}

void count_sort(int* arr, int size)
{
	int min{ 10 };
	int max{ 24 };
	int dif{ max - min + 1 };

	int* COUNTS = new int[dif] {};

	for (int i{ 0 }; i < size; ++i)
	{
		COUNTS[arr[i] - min] += 1;
	}

	int counter{0};
	for (int i{ 0 }; i < dif; ++i)
	{
		while (COUNTS[i] > 0)
		{
			arr[counter++] = i + min;
			COUNTS[i] -= 1;
		}
	}

	delete[] COUNTS;
}

void printArr(int* arr, int size)
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}
