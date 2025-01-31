#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Recursion for House Robber 1
    int helper(int i, vector<int> &nums,vector<int> &dp) {
        int n = nums.size();
        if (i >= n) return 0;
        if(dp[i] != -1) return dp[i]; 
        int take = nums[i] + helper(i + 2, nums,dp);
        int notTake = helper(i + 1, nums,dp);
        return dp[i] = max(take, notTake);
    }

    int rob(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
             int take = nums[i] + dp[i-2];
             int nottake = dp[i-1];
             dp[i] = max(take,nottake);
        }
        return dp[n-1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Maximum amount that can be robbed: " << sol.rob(nums) << endl;
    return 0;
}