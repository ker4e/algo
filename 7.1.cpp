#include <iostream>
#include <fstream>

void create_input_file();
int** create_matrix(int size);
void delete_matrix(int** matrix, int size);
void read_matrix(std::ifstream& input, int** matrix, int size);
void depth_first_search(int vertex, int** matrix, bool* visited, int size);

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

    int** matrix = create_matrix(size);
    read_matrix(input, matrix, size);

    input.close();

    bool* visited = new bool[size];

    for (int i = 0; i < size; ++i) 
    {
        visited[i] = false;
    }

    std::cout << "Depth first search order: ";
    depth_first_search(0, matrix, visited, size);

    std::cout << std::endl;

    delete_matrix(matrix, size);
    delete[] visited;

    return 0;
}

void create_input_file() 
{
    std::ofstream file("input.txt");

    if (!file.is_open()) 
    {
        std::cout << "File creation error" << std::endl;
        return;
    }

    file << 7 << std::endl;
    file << "0 0 1 0 0 1 1" << std::endl;
    file << "0 0 1 1 0 0 1" << std::endl;
    file << "1 1 0 0 0 0 1" << std::endl;
    file << "0 1 0 0 1 0 0" << std::endl;
    file << "0 0 0 1 0 0 1" << std::endl;
    file << "1 0 0 0 0 0 1" << std::endl;
    file << "1 1 1 0 1 1 0" << std::endl;

    file.close();
}

int** create_matrix(int size) 
{
    int** matrix = new int*[size];

    for (int i = 0; i < size; ++i) 
    {
        matrix[i] = new int[size];
    }

    return matrix;
}

void delete_matrix(int** matrix, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void read_matrix(std::ifstream& input, int** matrix, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            input >> matrix[i][j];
        }
    }
}

void depth_first_search(int vertex, int** matrix, bool* visited, int size) {
    visited[vertex] = true;

    std::cout << vertex + 1 << " ";

    for (int i = 0; i < size; ++i) 
    {
        if (matrix[vertex][i] == 1 && !visited[i]) 
        {
            depth_first_search(i, matrix, visited, size);
        }
    }
}
