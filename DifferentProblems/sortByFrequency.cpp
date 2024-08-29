#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        vector<int> res;
        map<int, int> freq;

        // Step 1: Count the frequency of each element
        for (int num : arr) {
            freq[num]++;
        }

        // Step 2: Store the frequency data in a vector of pairs
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());

        // Step 3: Sort the vector by frequency (descending) and then by element value (ascending)
        sort(freqVec.begin(), freqVec.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        });

        // Step 4: Construct the result vector
        for (auto& it : freqVec) {
            while (it.second--) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};

int main() {
    vector<int> arr = {5, 5, 4, 6, 4, 6, 6, 6, 5};
    Solution sol;
    vector<int> sortedArr = sol.sortByFreq(arr);
    
    // Output the sorted array
    for (int num : sortedArr) {
        cout << num << " ";
    }
    
    return 0;
}
