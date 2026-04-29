#include <iostream>
#include <fstream>

void create_input_file();
void topological_sort(int vertex, int** matrix, bool* visited, int* result, int& position, int size);

int main() {
    create_input_file();

    std::ifstream input("input.txt");

    if (!input.is_open()) 
    {
        std::cout << "File opening error" << std::endl;
        return 1;
    }

    int size;
    input >> size;

    int** matrix = new int*[size];

    for (int i = 0; i < size; ++i) 
    {
        matrix[i] = new int[size];
    }

    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            input >> matrix[i][j];
        }
    }
    input.close();

    bool* visited = new bool[size];

    for (int i = 0; i < size; ++i) 
    {
        visited[i] = false;
    }

    int* result = new int[size];
    int position = size - 1;

    for (int i = 0; i < size; ++i) 
    {
        if (!visited[i]) 
        {
            topological_sort(i, matrix, visited, result, position, size);
        }
    }

    std::cout << "Topological order of vertices: ";

    for (int i = 0; i < size; ++i) 
    {
        std::cout << result[i] << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < size; ++i) 
    {
        delete[] matrix[i];
    }

    delete[] matrix;
    delete[] visited;
    delete[] result;

    return 0;
}

void create_input_file() 
{
    std::ofstream file("input.txt");

    file << 9 << std::endl;
    file << "0 0 1 0 0 0 0 0 0" << std::endl;
    file << "0 0 0 0 0 0 0 0 0" << std::endl;
    file << "0 0 0 0 1 0 1 0 0" << std::endl;
    file << "0 0 0 0 0 0 0 0 0" << std::endl;
    file << "0 0 0 0 0 1 0 0 0" << std::endl;
    file << "0 1 0 1 0 0 1 0 0" << std::endl;
    file << "0 0 0 0 0 0 0 1 0" << std::endl;
    file << "0 0 0 0 0 0 0 0 0" << std::endl;
    file << "1 0 0 0 0 0 0 0 0" << std::endl;

    file.close();
}

void topological_sort(int vertex, int** matrix, bool* visited, int* result, int& position, int size) 
{
    visited[vertex] = true;

    for (int i = 0; i < size; ++i) 
    {
        if (matrix[vertex][i] == 1 && !visited[i]) 
        {
            topological_sort(i, matrix, visited, result, position, size);
        }
    }

    result[position] = vertex + 1;
    --position;
}
