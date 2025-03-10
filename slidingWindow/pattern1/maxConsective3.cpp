// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            // approach sliding window
            // jb 0 count bada hoga k size se tbhich window ko aage badhana hai 
            int left = 0, maxLen = 0, zeroCount = 0;

            for (int right = 0; right < nums.size(); right++) {
                if (nums[right] == 0) zeroCount++;  // Count zeros in window
        
                // Shrink window if zero count exceeds k
                while (zeroCount > k) {
                    if (nums[left] == 0) zeroCount--;  
                    left++;  // Move left boundary
                }
        
                // Update max length
                maxLen = max(maxLen, right - left + 1);
            }
        
            return maxLen;
        }
    };