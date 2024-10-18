#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& allSubsets) {
    // Base case: reached the end of the array
    if (index == nums.size()) {
        allSubsets.push_back(currentSubset);  // Store the current subset
        return;
    }
    
    // Case 1: Include the current element in the subset
    currentSubset.push_back(nums[index]);
    generateSubsets(nums, index + 1, currentSubset, allSubsets);

    // Case 2: Do not include the current element in the subset
    currentSubset.pop_back(); // Backtrack
    generateSubsets(nums, index + 1, currentSubset, allSubsets);
}

int main() {
    vector<int> nums = {1, 2, 3};  // Example input
    vector<vector<int>> allSubsets;
    vector<int> currentSubset;

    // Call the function to generate all subsets
    generateSubsets(nums, 0, currentSubset, allSubsets);

    // Output all subsets
    cout << "All subsets are:\n";
    for (const auto& subset : allSubsets) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout <<endl;
    }

    return 0;
}
