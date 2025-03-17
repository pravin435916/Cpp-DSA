// Optimal Approach (Sliding Window)
// The trick here is to count the number of subarrays that contain exactly k odd numbers.
// We do this by:

// Counting the number of subarrays with at most k odd numbers.
// Counting the number of subarrays with at most k-1 odd numbers.
// The difference between these two counts gives the number of subarrays with exactly k odd numbers.
// Formula:

// exactlyK(nums, k) =  atMostK(nums, k) − atMostK(nums, k-1)
class Solution {
    public:
        int numberOfSubarrays(vector<int>& nums, int k) {
            return atMostK(nums, k) - atMostK(nums, k - 1);
        }
        private:
         int atMostK(std::vector<int>& nums, int k) {
            int left = 0, right = 0, oddCount = 0, result = 0;
            
            while (right < nums.size()) {
                if (nums[right] % 2 == 1) oddCount++;  
                // Increment odd count if current number is odd
                
                while (oddCount > k) {  // Shrink the window if odd numbers exceed k
                    if (nums[left] % 2 == 1) oddCount--;
                    left++;
                }
                
                result += (right - left + 1);  
                // Add the number of valid subarrays ending at right
                right++;
            }
            
            return result;
        }
    };