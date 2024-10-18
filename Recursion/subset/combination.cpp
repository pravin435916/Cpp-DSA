#include <iostream>
#include <vector>
using namespace std;

void combinationSum(vector<int>& nums, int index, int target, vector<int>& current, vector<vector<int>>& result) {
    // Base case: if target becomes 0, add the current combination to the result
    if (target == 0) {
        result.push_back(current);
        return;
    }

    // Base case: if the index reaches the size of the array or target goes below 0
    if (index == nums.size() || target < 0) return;

    // Take the current element and recursively find combinations
    current.push_back(nums[index]);
    combinationSum(nums, index, target - nums[index], current, result); // Don't increment index, allow repeated elements

    // Backtrack: remove the last element and explore the next possibility (not taking the current element)
    current.pop_back();
    combinationSum(nums, index + 1, target, current, result); // Move to the next element
}

int main() {
    vector<int> nums = {1, 2, 3, 4}; 
    int target = 6; // Target sum
    
    vector<vector<int>> result; // To store the combinations
    vector<int> current; // To store the current combination
    
    combinationSum(nums, 0, target, current, result); // Start from index 0 with target sum

    // Print the result
    cout << "Combinations that sum up to " << target << ":" << endl;
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
