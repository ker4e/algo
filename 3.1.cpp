#include <iostream>

void merge_sort(int* arr, int size);
void printArr(int* arr, int size);

int main() 
{
	int arrayOne[]{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	int sizeOne{ sizeof(arrayOne) / sizeof(arrayOne[0]) };

	std::cout << "Array one before merge sort: ";
	printArr(arrayOne, sizeOne);
	merge_sort(arrayOne, sizeOne);

	std::cout << "Array one after merge sort: ";
	printArr(arrayOne, sizeOne);

	int arrayTwo[]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	int sizeTwo{ sizeof(arrayTwo) / sizeof(arrayTwo[0]) };

	std::cout << "\nArray two before merge sort: ";
	printArr(arrayTwo, sizeTwo);
	merge_sort(arrayTwo, sizeTwo);

	std::cout << "Array two after merge sort: ";
	printArr(arrayTwo, sizeTwo);

	int arrayThree[]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	int sizeThree{ sizeof(arrayThree) / sizeof(arrayThree[0]) };

	std::cout << "\nArray three before merge sort: ";
	printArr(arrayThree, sizeThree);
	merge_sort(arrayThree, sizeThree);

	std::cout << "Array three after merge sort: ";
	printArr(arrayThree, sizeThree);

	return EXIT_SUCCESS;
}

void merge_sort(int* arr, int size) 
{
	if (size <= 1)
		return;

	
	int mid{ size / 2 };

	merge_sort(arr, mid);
	merge_sort(arr + mid, size - mid);

	int sizeArr{ 0 };
	int sizeArr1{ 0 };
	int sizeArr2{ 0 };

	int* arrOne = new int[mid];
	int* arrTwo = new int[size - mid];

	for (int i = 0; i < mid; i++)
		arrOne[i] = arr[i];

	for (int i = 0; i < size - mid; i++)
		arrTwo[i] = arr[mid + i];

	while (sizeArr1 < mid || sizeArr2 < (size - mid))
	{
		if (sizeArr1 == mid)
		{
			arr[sizeArr] = arrTwo[sizeArr2];
			sizeArr2 += 1;
		}
		else if (sizeArr2 == (size - mid))
		{
			arr[sizeArr] = arrOne[sizeArr1];
			sizeArr1 += 1;
		}
		else
		{
			if (arrOne[sizeArr1] <= arrTwo[sizeArr2])
			{
				arr[sizeArr] = arrOne[sizeArr1];
				sizeArr1 += 1;
			}
			else
			{
				arr[sizeArr] = arrTwo[sizeArr2];
				sizeArr2 += 1;
			}
		}
		sizeArr += 1;
	}
	delete[] arrOne;
	delete[] arrTwo;
}

void printArr(int* arr, int size) 
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}
