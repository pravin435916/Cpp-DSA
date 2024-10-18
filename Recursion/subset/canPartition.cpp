#include <iostream>
#include <vector>
using namespace std;

// Recursive function to check if there exists a subset with a given target sum
bool canPartition(vector<int>& nums, int index, int currentSum, int target) {
    // Base case: if the current sum equals the target, return true
    if (currentSum == target) return true;
    
    // Base case: if we've processed all elements or if the current sum exceeds the target, return false
    if (index == nums.size() || currentSum > target) return false;

    // Recursive case: include the current element or exclude it
    return canPartition(nums, index + 1, currentSum + nums[index], target) || 
           canPartition(nums, index + 1, currentSum, target);
}

bool canPartitionArray(vector<int>& nums) {
    int totalSum = 0;
    
    // Calculate the total sum of the array
    for (int num : nums) totalSum += num;
    
    // If the total sum is odd, it's not possible to partition into two equal subsets
    if (totalSum % 2 != 0) return false;

    // Target sum for one subset is half of the total sum
    int target = totalSum / 2;

    // Start recursive backtracking to check if there's a subset with the target sum
    return canPartition(nums, 0, 0, target);
}

int main() {
    vector<int> nums = {1, 5, 2, 3,  11, 5}; // Example input
    if (canPartitionArray(nums)) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }

    return 0;
}
