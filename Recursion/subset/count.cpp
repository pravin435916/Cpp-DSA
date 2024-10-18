#include <iostream>
#include <vector>
using namespace std;

int countSubsets(vector<int>& nums, int index, int currentSum, int target) {
    if (index == nums.size()) {
        return currentSum == target ? 1 : 0;
    }
    int take = countSubsets(nums, index + 1, currentSum + nums[index], target); 
    int NotTake = countSubsets(nums, index + 1, currentSum, target); 

    // Return the sum of both cases 
    return take + NotTake;
}

int main() {
    vector<int> nums = {1, 2, 3, 4}; 
    int target = 5; // Target sum
    int result = countSubsets(nums, 0, 0, target); // Start from index 0 and current sum 0

    cout << "Number of subsets with sum " << target << " is: " << result << endl;

    return 0;
}
