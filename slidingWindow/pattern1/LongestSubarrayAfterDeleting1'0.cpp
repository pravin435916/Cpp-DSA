class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int left=0, zeroCount=0,maxi = INT_MIN;
            int n = nums.size();
    
            for(int right=0;right<n;right++){
                if(nums[right] == 0) zeroCount++;
    
                if(zeroCount > 1) {
                    if(nums[left] == 0) zeroCount--;
                    left++;
                }
                maxi = max(maxi,right-left+1);
            }
            return maxi-1;
        }
    };
//     Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].