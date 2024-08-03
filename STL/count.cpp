#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <algorithm> 
using namespace std;
int main() {
    vector<int> vec = {1, 0, 1, 1, 0, 1, 0, 0, 1};

    // Use std::accumulate with a lambda to count the number of 1s
    // int countOnes = std::accumulate(vec.begin(), vec.end(), 0, 
    //                                 [](int count, int val) { return count + (val == 1 ? 1 : 0); });
    int countOnes = std::count(vec.begin(),vec.end(),1);

    std::cout << "Number of 1s: " << countOnes << std::endl;

    return 0;
}
