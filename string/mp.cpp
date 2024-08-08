#include <iostream>
#include <string>
#include <vector>

bool isSubstring(std::string s, std::string sub, std::vector<std::pair<char, char>> mappings) {
    // Replace characters in sub according to the mappings
    for (auto& c : sub) {
        for (auto& m : mappings) {
            if (c == m.first) {
                c = m.second;
                break;
            }
        }
    }

    // Check if the modified sub is a substring of s
    return s.find(sub) != std::string::npos;
}

int main() {
    std::string s = "fool3e7bar";
    std::string sub = "leet";
    std::vector<std::pair<char, char>> mappings = {{'e','3'},{'t','7'},{'t','8'}};
    std::cout << std::boolalpha << isSubstring(s, sub, mappings) << std::endl;  // Output: true
    return 0;
}

