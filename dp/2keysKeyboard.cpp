class Solution {
public:
    
    int helper(int cur,int clip,int n, vector<vector<int>>& dp) {
        if(cur == n) return 0;
        if(cur > n) return 10001;
        if (dp[cur][clip] != -1) return dp[cur][clip];
        int copyAllandPaste = 1 + 1 + helper(cur+cur,cur,n,dp);
        int paste = 1 + helper(cur+clip,clip,n,dp);
        return dp[cur][clip] = min(copyAllandPaste,paste);
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return 1 + helper(1,1,n,dp);
    }
};