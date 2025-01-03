// 2270. Number of Ways to Split Array
// You are given a 0-indexed integer array nums of length n.

// nums contains a valid split at index i if the following are true:

// The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
// There is at least one element to the right of i. That is, 0 <= i < n - 1.
// Return the number of valid splits in nums.

//brute force 
#include <vector>
#include <numeric>
using namespace std;

int waysToSplitArray(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    
    // Iterate through all possible split points
    for (int i = 0; i < n - 1; i++) {
        // Calculate the sum of the left and right parts
        long long leftSum = 0, rightSum = 0;

        for (int j = 0; j <= i; j++) {
            leftSum += nums[j];
        }
        
        for (int j = i + 1; j < n; j++) {
            rightSum += nums[j];
        }

        // Check if the condition is satisfied
        if (leftSum >= rightSum) {
            count++;
        }
    }
    
    return count;
}


//optimized using prefix sum
#include <vector>
#include <numeric>
using namespace std;

int waysToSplitArray(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    
    // Step 1: Calculate total sum of the array
    long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);

    // Step 2: Calculate prefix sum iteratively
    long long prefixSum = 0;
    
    for (int i = 0; i < n - 1; i++) {
        // Update prefix sum to include nums[i]
        prefixSum += nums[i];
        
        // Calculate right sum using totalSum and prefixSum
        long long rightSum = totalSum - prefixSum;

        // Step 3: Check the condition
        if (prefixSum >= rightSum) {
            count++;
        }
    }
    
    return count;
}


//apraoch 3
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Keep track of sum of elements on left and right sides
        long long leftSum = 0, rightSum = 0;

        // Initially all elements are on right side
        for (int num : nums) {
            rightSum += num;
        }

        int count = 0;
        // Try each possible split position
        for (int i = 0; i < nums.size() - 1; i++) {
            // Move current element from right to left side
            leftSum += nums[i];
            rightSum -= nums[i];

            // Check if this creates a valid split
            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};