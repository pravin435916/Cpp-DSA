class Solution {
public:
    // top down
    int helper(vector<vector<int>> &v,int i,int j,vector<vector<int>> &dp) {
        if(i>=0 && j>=0 && v[i][j] == 1) return 0;  //additional case for obstacle
        if(i == 0 && j == 0) return 1;
        if(j<0 || i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int left = helper(v,i,j-1,dp);
        int up = helper(v,i-1,j,dp);
        return dp[i][j] = left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(v,n-1,m-1,dp);
    }
};