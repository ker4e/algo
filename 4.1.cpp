#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size); 

int main() {
    int actual_size{}, logical_size{};

    std::cout << "Enter actual size: ";
    std::cin >> actual_size;

    std::cout << "Enter logical size: ";
    std::cin >> logical_size;

    if (logical_size > actual_size) {
        std::cout << "Error: logical size cannot be greater than actual size!" << std::endl;
        return 1;
    }

    int* arr = new int[actual_size];

    std::cout << "Enter " << logical_size << " elements: ";
    for (int i = 0; i < logical_size; i++) {
        std::cin >> arr[i];
    }

    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;
    return EXIT_SUCCESS;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    for (int i = 0; i < actual_size; i++) {
        if (i < logical_size) {
            std::cout << arr[i];
        }
        else {
            std::cout << "_";
        }

        if (i != actual_size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
