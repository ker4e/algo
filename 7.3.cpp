#include <iostream>
#include <fstream>

void create_input_file_first_example();
void create_input_file_second_example();
int** create_matrix(int size);
void delete_matrix(int** matrix, int size);
void read_matrix(std::ifstream& input, int** matrix, int size);
bool* create_visited_array(int size);
void clear_visited_array(bool* visited, int size);
bool search_cycle_from_vertex(int current_vertex,  int parent_vertex, int** matrix, bool* visited, int size);
bool graph_has_cycle(int** matrix, int size);

int main() {
    create_input_file_first_example();

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

    if (graph_has_cycle(matrix, size)) 
    {
        std::cout << "The graph has a cycle!" << std::endl;
    } else {
        std::cout << "The graph has no cycles" << std::endl;
    }

    delete_matrix(matrix, size);

    return 0;
}

void create_input_file_first_example() 
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

void create_input_file_second_example() 
{
    std::ofstream file("input.txt");

    if (!file.is_open()) 
    {
        std::cout << "File creation error" << std::endl;
        return;
    }

    file << 4 << std::endl;
    file << "0 0 1 0" << std::endl;
    file << "0 0 1 1" << std::endl;
    file << "1 1 0 0" << std::endl;
    file << "0 1 0 0" << std::endl;

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

bool* create_visited_array(int size) 
{
    bool* visited = new bool[size];

    clear_visited_array(visited, size);

    return visited;
}

void clear_visited_array(bool* visited, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        visited[i] = false;
    }
}

bool search_cycle_from_vertex(int current_vertex, int parent_vertex, int** matrix, bool* visited, int size) 
{
    visited[current_vertex] = true;

    for (int i = 0; i < size; ++i) 
    {
        if (matrix[current_vertex][i] == 1) 
        {
            if (!visited[i]) 
            {
                if (search_cycle_from_vertex(i, current_vertex, matrix, visited, size)) 
                {
                    return true;
                }
            } 
            else if (i != parent_vertex) 
            {
                return true;
            }
        }
    }

    return false;
}

bool graph_has_cycle(int** matrix, int size) 
{
    bool* visited = create_visited_array(size);

    for (int i = 0; i < size; ++i) 
    {
        if (!visited[i]) 
        {
            if (search_cycle_from_vertex(i, -1, matrix, visited, size)) 
            {
                delete[] visited;
                return true;
            }
        }
    }

    delete[] visited;
    return false;
}
