// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1] 

class Solution {
    public:
        int f(vector<int>& nums, int goal) {
            int n = nums.size();
            if (goal < 0) return 0;  // Edge case for negative goal
            int l = 0, r = 0, count = 0, currSum = 0;
    
            while (r < n) {
                currSum += nums[r];
                while (currSum > goal) {
                    currSum -= nums[l];
                    l++;
                }
                count += (r - l + 1);  // Number of valid subarrays
                r++;
            }
            return count;
        }
    
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            return f(nums, goal) - f(nums, goal - 1);
        }
    };