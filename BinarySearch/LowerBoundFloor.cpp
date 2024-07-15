class Solution {
  public:
    int findFloor(vector<long long> nums, long long n, long long target) {
        int low = 0;
        int high = n-1;
        int val = -1;
        while(low <= high) {
            int mid = low + (high - low) /2;
            if(nums[mid] <= target) {
                val = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return val;
    }
};
// Input: n = 7, x = 0 arr[] = {1,2,8,10,11,12,19}
// Output: -1
// Explanation: No element less than 0 is found. So output is "-1".
// Input: n = 7, x = 5 arr[] = {1,2,8,10,11,12,19}
// Output: 1
// Explanation: Largest Number less than 5 is 2 (i.e k = 2), whose index is 1(0-based indexing).