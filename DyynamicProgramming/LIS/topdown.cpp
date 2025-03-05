class Solution {
    public:
        vector<vector<int>> dp;
        int solve(int idx,int prev,int n,vector<int> &nums) {
            if(idx==n) return 0;
            if (dp[idx][prev + 1] != -1) return dp[idx][prev + 1];
            int nottake = solve(idx+1,prev,n,nums);
            int take = 0;
            if(prev == -1 || nums[prev] < nums[idx]) {
                take = 1 + solve(idx+1,idx,n,nums);
            }
    
            return dp[idx][prev + 1] = max(take,nottake);
            
        }
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            dp.assign(n, vector<int>(n + 1, -1));
            return solve(0,-1,n,nums);
        }
    };

//     Time Complexity (Memoized DP)
// Each unique (idx, prev) state is computed only once and stored in dp[idx][prev + 1].
// Since idx goes from 0 to N-1 and prev goes from -1 to N-1, there are at most O(N²) states.
// Each state is computed in constant time O(1) (only a few operations).
// Total Time Complexity: O(N²).
// Space Complexity (Memoized DP)
// O(N²) (for DP table dp[n][n+1]).
// O(N) (for Recursion Stack) (since at most N recursive calls are stacked).
// Total Space Complexity: O(N²) + O(N) = O(N²).