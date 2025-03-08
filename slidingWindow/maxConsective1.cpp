class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int ct=0,ans=0;
            for(int i=0;i<nums.size();i++) {
                if(nums[i] == 1) ct++;   // 1 1 0 1 1 1 0 1
                else ct=0;               // 1 2 0 1 2 3 0 1   count 
                ans = max(ans,ct);       // 1 2 2 2 2 3 3 3   ans of max of count and ans
            }
            return ans;
        }
    };