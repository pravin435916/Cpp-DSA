// 646. Maximum Length of Pair Chain
// Input: pairs = [[1,2],[7,8],[4,5]]
// Output: 3
// Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
class Solution {
    public:
        vector<vector<int>> dp;
        int solve(int idx,int prev,int n,vector<vector<int>>& pairs) {
            if(idx==n) return 0;
            if (dp[idx][prev + 1] != -1) return dp[idx][prev + 1];
            int nottake = solve(idx+1,prev,n,pairs);
            int take = 0;
            if(prev == -1 || pairs[prev][1] < pairs[idx][0]) {
                take = 1 + solve(idx+1,idx,n,pairs);
            }
    
            return dp[idx][prev + 1] = max(take,nottake);
            
        }
        int findLongestChain(vector<vector<int>>& pairs) {
            int n = pairs.size();
            sort(pairs.begin(),pairs.end());
            dp.assign(n, vector<int>(n + 1, -1));
            return solve(0,-1,n,pairs);
        }
    };