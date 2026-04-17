#include <iostream>
#include <string>

int simple_string_hash(const std::string& s) {
    int hash_value = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        hash_value += s[i];
    }
    return hash_value;
}

int main() {
    std::string input;

    while (true) {
        std::cout << "Enter a string: ";
        std::getline(std::cin >> std::ws, input);

        int hash_result = simple_string_hash(input);
        std::cout << "Simple hash of string ' " << input << " ' = " << hash_result << std::endl;
      
        if (input == "exit") {
            break;
        }
    }
    return 0;
}
