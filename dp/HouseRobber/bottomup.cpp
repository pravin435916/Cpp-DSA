class Solution {
public:
    int robHelper(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        return dp[n-1];
    }
    int robHelper(vector<int>& nums) {
        int prev1 = 0, prev2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            int curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Edge case: Only one house

        // Case 1: Exclude the first house
        vector<int> temp1(nums.begin() + 1, nums.end());
        // Case 2: Exclude the last house
        vector<int> temp2(nums.begin(), nums.end() - 1);

        // Calculate the max for both cases using the bottom-up DP approach
        return max(robHelper(temp1), robHelper(temp2));
    }
};
