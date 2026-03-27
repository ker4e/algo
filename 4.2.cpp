#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size);
void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int value); 

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

    int value;
    while (true) {
        std::cout << "Enter element to append (0 to stop): ";
        std::cin >> value;

        if (value == 0) {
            break;
        }

        append_to_dynamic_array(arr, logical_size, actual_size, value);
        print_dynamic_array(arr, logical_size, actual_size);
    }

    std::cout << "Final array: ";
    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;
    return 0;
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

void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int value) {
    if (logical_size < actual_size) {
        arr[logical_size] = value;
        logical_size++;
    }
    else {
        // увеличиваем массив
        int new_actual_size = actual_size * 2;
        int* new_arr = new int[new_actual_size];

        for (int i = 0; i < logical_size; i++) {
            new_arr[i] = arr[i];
        }
        new_arr[logical_size] = value;

        // освобождаем старую память
        delete[] arr;

        // переназначаем указатель
        arr = new_arr;

        logical_size++;
        actual_size = new_actual_size;
    }
}
