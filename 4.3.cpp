#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size);
void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size);

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

    //удаление первого элемента
    std::string answer;

    while (logical_size > 0) {
        std::cout << "Delete first element? (yes/no): ";
        std::cin >> answer;

        if (answer == "no") {
            std::cout << "Thank you! Final array: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }

        if (answer == "yes") {
            remove_dynamic_array_head(arr, logical_size, actual_size);

            if (logical_size == 0) {
                std::cout << "Array is empty. Goodbye!" << std::endl;
                break;
            }

            print_dynamic_array(arr, logical_size, actual_size);
        }
    }

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

void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size) {
    if (logical_size == 0) return;

    if ((logical_size - 1) > actual_size / 3) {
        for (int i = 1; i < logical_size; i++) {
            arr[i - 1] = arr[i];
        }
        logical_size--;
    }
    else {
        //уменьшаем массив
        int new_actual_size = actual_size / 3;
        if (new_actual_size < 1) new_actual_size = 1;

        int* new_arr = new int[new_actual_size];

        for (int i = 1; i < logical_size; i++) {
            new_arr[i - 1] = arr[i];
        }

        delete[] arr;
        arr = new_arr;

        logical_size--;
        actual_size = new_actual_size;
    }
}
