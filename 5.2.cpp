#include <iostream>
#include <string>

int real_string_hash(const std::string& s, int p, int n) {
    int hash_value = 0;
    int p_power = 1;

    for (size_t i = 0; i < s.size(); ++i) {
        hash_value = (hash_value + (s[i] * p_power) % n) % n;
        p_power = (p_power * p) % n;
    }
    return hash_value;
}

int main() {
    int p, n;
    std::string input;

    std::cout << "Enter p: ";
    std::cin >> p;

    std::cout << "Enter n: ";
    std::cin >> n;

    while (true) {
        std::cout << "Enter a string: ";
        std::getline(std::cin >> std::ws, input);

        int hash_result = real_string_hash(input, p, n);
        std::cout << "Hash of string " << input << " = " << hash_result << std::endl;

        if (input == "exit") {
            break;
        }
    }
    return 0;
}
