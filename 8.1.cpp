#include <iostream>
#include <fstream>

void create_input_file();
int** create_matrix(int size);
void delete_matrix(int** matrix, int size);
void read_matrix(std::ifstream& input, int** matrix, int size);
void print_directed_graph(int** matrix, int size);

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

    print_directed_graph(matrix, size);

    delete_matrix(matrix, size);

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

void print_directed_graph(int** matrix, int size) 
{
    std::cout << "Text view of directed graph:" << std::endl;

    for (int i = 0; i < size; ++i) 
    {
        bool has_edges = false;

        std::cout << i + 1 << ": ";

        for (int j = 0; j < size; ++j) 
        {
            if (matrix[i][j] == 1) {
                std::cout << j + 1 << " ";
                has_edges = true;
            }
        }

        if (!has_edges) 
        {

            std::cout << "none";
        }

        std::cout << std::endl;
    }
}
