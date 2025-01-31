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
        if(n==1) return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++) {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);

        return max(helper(0,temp1,dp1),helper(0,temp2,dp2));
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Maximum amount that can be robbed: " << sol.rob(nums) << endl;
    return 0;
}