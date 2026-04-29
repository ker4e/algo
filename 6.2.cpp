#include <iostream>
#include <string>

enum Command {
    UP,
    LEFT,
    RIGHT,
    EXIT,
    UNKNOWN
};

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

    while (value > 1) 
    {
        value /= 2;
        ++level;
    }

    return level;
}

void print_element(const int* arr, int index) 
{
    int level = get_level(index);

    if (index == 0) 
    {
        std::cout << level << " root " << arr[index];
        return;
    }

    int parent_index = (index - 1) / 2;

    if (index % 2 == 1) 
    {
        std::cout << level << " left(" << arr[parent_index] << ") " << arr[index];
    } 
    else {
        std::cout << level << " right(" << arr[parent_index] << ") " << arr[index];
    }
}

void print_pyramid(const int* arr, int size) 
{
    std::cout << "Pyramid:" << std::endl;

    for (int i = 0; i < size; ++i) {
        print_element(arr, i);
        std::cout << std::endl;
    }
}

Command get_command(const std::string& command) {
    if (command == "up") 
    {
        return UP;
    }

    if (command == "left") 
    {
        return LEFT;
    }

    if (command == "right") 
    {
        return RIGHT;
    }

    if (command == "exit") 
    {
        return EXIT;
    }

    return UNKNOWN;
}

void travel_pyramid(const int* arr, int size) 
{
    int current_index = 0;
    std::string command;

    while (true) {
        std::cout << "You are here: ";
        print_element(arr, current_index);
        std::cout << std::endl;

        std::cout << "Enter command: ";
        std::cin >> command;

        switch (get_command(command)) {
        case UP:
            if (current_index == 0) 
            {
                std::cout << "Error! Parent is missing" << std::endl;
            } 
            else {
                current_index = (current_index - 1) / 2;
                std::cout << "Ok" << std::endl;
            }
            break;

        case LEFT: 
          {
            int left_index = 2 * current_index + 1;

            if (left_index >= size) {
                std::cout << "Error! Left child is missing" << std::endl;
            } else {
                current_index = left_index;
                std::cout << "Ok" << std::endl;
            }
            break;
        }

        case RIGHT: 
          {
            int right_index = 2 * current_index + 2;

            if (right_index >= size) {
                std::cout << "Error! Right child is missing" << std::endl;
            } else {
                current_index = right_index;
                std::cout << "Ok" << std::endl;
            }
            break;
        }

        case EXIT:
            return;

        case UNKNOWN:
            std::cout << "Error! Unknown command" << std::endl;
            break;
        }
    }
}

void run_example(const int* arr, int size) 
{
    print_array(arr, size);
    print_pyramid(arr, size);
    travel_pyramid(arr, size);
}

int main() 
{
    int arr1[] = {1, 3, 6, 5, 9, 8};
    int arr2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int arr3[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    run_example(arr1, size1);

    return 0;
}
