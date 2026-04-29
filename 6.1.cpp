#include <iostream>

void print_array(const int* arr, int size);
int get_level(int index);
void print_pyramid(const int* arr, int size);

int main() {
    int arr1[] = {1, 3, 6, 5, 9, 8};
    int arr2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int arr3[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    print_array(arr1, size1);
    print_pyramid(arr1, size1);

    std::cout << std::endl;

    print_array(arr2, size2);
    print_pyramid(arr2, size2);

    std::cout << std::endl;

    print_array(arr3, size3);
    print_pyramid(arr3, size3);

    return 0;
}

void print_array(const int* arr, int size) 
{
    std::cout << "Original array: ";

    for (int i = 0; i < size; ++i) 
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int get_level(int index) 
{
    int level = 0;
    int value = index + 1;

    while (value > 1) {
      
        value /= 2;
        ++level;
    }

    return level;
}

void print_pyramid(const int* arr, int size) 
{
    std::cout << "Pyramid:" << std::endl;

    if (size <= 0) 
    {
        return;
    }

    std::cout << "0 root " << arr[0] << std::endl;

    for (int i = 1; i < size; ++i) 
    {
        int level = get_level(i);
        int parent_index = (i - 1) / 2;

        if (i % 2 == 1) 
        {
            std::cout << level << " left(" << arr[parent_index] << ") " << arr[i] << std::endl;
        } else 
        {
            std::cout << level << " right(" << arr[parent_index] << ") " << arr[i] << std::endl;
        }
    }
}
