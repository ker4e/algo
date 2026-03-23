#include <iostream>
#include <vector>

int Fibonacci(std::vector<int>& arr, int n);

int main()
{
    int size = 25;
    std::vector<int> arr(size, -1);

    std::cout << "Fibonacci: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << Fibonacci(arr, i) << " ";
    }
}

int Fibonacci(std::vector<int>& arr, int n)
{
    if (n <= 1) { return n; }

    if (arr[n] != -1) { return arr[n]; }

    arr[n] = Fibonacci(arr, n - 1) + Fibonacci(arr, n - 2);
    return arr[n];
}
