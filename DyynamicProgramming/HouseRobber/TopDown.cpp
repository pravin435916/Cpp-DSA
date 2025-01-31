#include <iostream>
#include <vector>
using namespace std;
// Time Complexity :- o(n)
// Space :- o(n) for recursion stack
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
        vector<int> dp(n,-1);
        return helper(0, nums,dp);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Maximum amount that can be robbed: " << sol.rob(nums) << endl;
    return 0;
}