#include <iostream>
#include <string>

int find_substring_light_rabin_karp(const std::string& text, const std::string& pattern) {
    if (pattern.size() > text.size()) return -1;

    for (size_t i = 0; i <= text.size() - pattern.size(); ++i) {
        int hash1 = 0;
        int hash2 = 0;

        for (size_t j = 0; j < pattern.size(); ++j) {
            hash1 += pattern[j];
            hash2 += text[i + j];
        }

        if (hash1 == hash2) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::string text, pattern;

    std::cout << "Enter the string to search in: ";
    std::getline(std::cin >> std::ws, text);

    while (true) {
        std::cout << "Enter the substring to find: ";
        std::getline(std::cin >> std::ws, pattern);

        int index = find_substring_light_rabin_karp(text, pattern);

        if (index != -1)
            std::cout << "Substring " << pattern << " found at index " << index << std::endl;
        else
            std::cout << "Substring " << pattern << " not found" << std::endl;

        if (pattern == "exit") break;
    }
    return 0;
}
