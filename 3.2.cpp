#include <iostream>

void quick_sort(int* arr, int size);
void printArr(int* arr, int size);

int main() 
{
	int arrayOne[]{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	int sizeOne{ sizeof(arrayOne) / sizeof(arrayOne[0]) };

	std::cout << "Array one before quick sort: ";
	printArr(arrayOne, sizeOne);
	quick_sort(arrayOne, sizeOne);

	std::cout << "Array one after quick sort: ";
	printArr(arrayOne, sizeOne);

	int arrayTwo[]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	int sizeTwo{ sizeof(arrayTwo) / sizeof(arrayTwo[0]) };

	std::cout << "\nArray two before quick sort: ";
	printArr(arrayTwo, sizeTwo);
	quick_sort(arrayTwo, sizeTwo);

	std::cout << "Array two after quick sort: ";
	printArr(arrayTwo, sizeTwo);

	int arrayThree[]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	int sizeThree{ sizeof(arrayThree) / sizeof(arrayThree[0]) };

	std::cout << "\nArray three before quick sort: ";
	printArr(arrayThree, sizeThree);
	quick_sort(arrayThree, sizeThree);

	std::cout << "Array three after quick sort: ";
	printArr(arrayThree, sizeThree);

	return EXIT_SUCCESS;
}

void quick_sort(int* arr, int size) 
{
	if (size <= 1) return;

	int left{ 0 };
	int right{ size - 1};
	int pivot = arr[size / 2];

	while (left <= right)
	{
		while (arr[left] < pivot)
			left += 1;
		while (arr[right] > pivot)
			right -= 1;
		if (left <= right)
		{
			std::swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
		quick_sort(arr, right + 1);
		quick_sort(arr + left, size - left);
}

void printArr(int* arr, int size) 
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}
