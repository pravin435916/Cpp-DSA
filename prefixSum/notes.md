## Why we need this approach of Hashmap +Prefix Sum ?
So basically for subarray related problems Brute Force method takes O(n^2) time to process each subarray + extra time in processing .
But with this approach only O(n) time is taken .


Now you might wonder that what is stopping you from using Sliding window approach for such problems
Sliding window is only applicable when we know for sure if the prefixsum is an increasing or decreasing function(i.e. Monotonous in nature)
So for problems where negative input is given this approach of PrefixSum + Hashmap is the best way to solve such problems.

## Sliding window is only applicable when we know for sure if the prefixsum is an increasing or decreasing function(i.e. Monotonous in nature)

## Basic Questions

1. **Find the sum of all elements in an array**
    - Tip: Use a simple loop to iterate through the array and keep a running sum.

2. **Find the sum of elements between two given indices**
    - Tip: Precompute the prefix sum array and use it to get the sum in constant time.

## Medium Questions

1. **Find the subarray with a given sum**
    - Tip: Use a hashmap to store the prefix sums and their indices.

2. **Count the number of subarrays with a given sum**
    - Tip: Use a hashmap to store the frequency of prefix sums.

## Hard Questions

1. **Find the maximum length of a subarray with a given sum**
    - Tip: Use a hashmap to store the first occurrence of each prefix sum.

2. **Find the subarray with the maximum sum**
    - Tip: Use Kadane's algorithm which is a variation of the prefix sum approach.

## Tips and Tricks

- Always initialize your prefix sum array with an extra 0 at the beginning.
- Use hashmaps to store prefix sums for quick lookups.
- Be mindful of edge cases such as empty subarrays or subarrays that include the first element.

## Cheatsheet

- **Prefix Sum Array**: An array where each element at index `i` is the sum of the elements from the start of the array up to `i`.
- **Hashmap**: A data structure that allows for fast retrieval of values based on keys, useful for storing prefix sums and their indices.
- **Kadane's Algorithm**: An efficient algorithm to find the maximum sum subarray in O(n) time.
## Example Code

### Basic Questions

1. **Find the sum of all elements in an array**
    ```cpp
    int sumOfArray(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return sum;
    }
    ```

2. **Find the sum of elements between two given indices**
    ```cpp
    int sumBetweenIndices(vector<int>& nums, int left, int right) {
        vector<int> prefixSum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return prefixSum[right + 1] - prefixSum[left];
    }
    ```

### Medium Questions

1. **Find the subarray with a given sum**
    ```cpp
    vector<int> subarrayWithSum(vector<int>& nums, int target) {
        unordered_map<int, int> prefixSumMap;
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            if (prefixSum == target) {
                return {0, i};
            }
            if (prefixSumMap.find(prefixSum - target) != prefixSumMap.end()) {
                return {prefixSumMap[prefixSum - target] + 1, i};
            }
            prefixSumMap[prefixSum] = i;
        }
        return {};
    }
    ```

2. **Count the number of subarrays with a given sum**
    ```cpp
    int countSubarraysWithSum(vector<int>& nums, int target) {
        unordered_map<int, int> prefixSumMap;
        int prefixSum = 0, count = 0;
        prefixSumMap[0] = 1;
        for (int num : nums) {
            prefixSum += num;
            if (prefixSumMap.find(prefixSum - target) != prefixSumMap.end()) {
                count += prefixSumMap[prefixSum - target];
            }
            prefixSumMap[prefixSum]++;
        }
        return count;
    }
    ```

### Hard Questions

1. **Find the maximum length of a subarray with a given sum**
    ```cpp
    int maxLengthSubarrayWithSum(vector<int>& nums, int target) {
        unordered_map<int, int> prefixSumMap;
        int prefixSum = 0, maxLength = 0;
        prefixSumMap[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            if (prefixSumMap.find(prefixSum - target) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[prefixSum - target]);
            }
            if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
                prefixSumMap[prefixSum] = i;
            }
        }
        return maxLength;
    }
    ```

2. **Find the subarray with the maximum sum**
    ```cpp
    int maxSubarraySum(vector<int>& nums) {
        int maxSum = nums[0], currentSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
    ```