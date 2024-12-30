class Solution {
public:
    //recursion
    int helper1(int index , vector<int> &nums,int n) {
        if(index >= n) return 0;
        return max(nums[index] + helper1(index+2,nums,n),helper1(index+1,nums,n));
    }
    // dp top down (recursive)
    int helper2(int index, vector<int>& nums, vector<int>& dp) {
        if (index >= nums.size()) return 0;
        if (dp[index] != -1) return dp[index];
        dp[index] = max(nums[index] + helper2(index + 2, nums, dp), helper2(index + 1, nums, dp));
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0]; //if only one element then it is answer 
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++) { 
            if(i!=0) temp1.push_back(nums[i]); //exclude first element
            if(i!=n-1) temp2.push_back(nums[i]); //exclude last element
        }
        // return helper1(0,nums,n);
        vector<int> dp(n, -1);
        vector<int> dp2(n, -1);
        return max(helper2(0, temp1, dp),helper2(0, temp2, dp2));
    }
};