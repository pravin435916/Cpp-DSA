#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> myMap;
    myMap["apple"] = 5;
    myMap["banana"] = 10;
    myMap["orange"] = 7;
    myMap.insert(std::make_pair("Grapes",12));
    myMap.insert(std::make_pair("KIWI",14));
    // Find the key associated with the maximum value
    std::string maxKey;
    int maxValue = INT16_MIN;
    for (auto pair : myMap) {
        if (pair.second > maxValue) {
            maxKey = pair.first;
            maxValue = pair.second;
        }
    }
    for(auto ch : myMap) {
        std::cout << ch.first<<" ";
    }

    std::cout<<std::endl;
    std::cout << "Key of maximum value: " << maxKey << std::endl;

    return 0;
}
