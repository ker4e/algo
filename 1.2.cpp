#include <iostream>
#include <algorithm>

int arrayFind(int refPoint, int* array, int elementsArr);

int main() 
{
	int elementsArr{};
	std::cout << "Enter the array size: ";
	std::cin >> elementsArr;

	int* arr = new int[elementsArr];
	for (int i{ 0 }; i < elementsArr; ++i)
	{
		std::cout << "Enter " << i << " element of array: ";
		std::cin >> arr[i];
	}
	std::sort(arr, arr + elementsArr);
	
	int refPoint;
	std::cout << "Enter a reference point: ";
	std::cin >> refPoint;

	std::cout << "The number of elements in the array is greater than " << refPoint << ": " << arrayFind(refPoint, arr, elementsArr) << std::endl;

	delete[] arr;

	return EXIT_SUCCESS;
}

int arrayFind(int refPoint, int* array, int elementsArr)
{
	int left{ 0 };
	int right{ elementsArr };
	
	while (left < right)
	{
		int middle = (left + right) / 2;

		if (array[middle] <= refPoint)
			left = middle + 1;
		else
			right = middle;
	}
	return elementsArr - left;
}
