#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> myMap;
    myMap["apple"] = 5;
    myMap["banana"] = 10;
    myMap["orange"] = 7;

    // Find the key associated with the maximum value
    std::string maxKey;
    int maxValue = std::numeric_limits<int>::min();
    for (const auto& pair : myMap) {
        if (pair.second > maxValue) {
            maxKey = pair.first;
            maxValue = pair.second;
        }
    }

    std::cout << "Key of maximum value: " << maxKey << std::endl;

    return 0;
}
