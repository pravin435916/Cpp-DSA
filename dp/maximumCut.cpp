class Solution
{
    public:
    int helper(int n,int x,int y,int z,vector<int> &dp) {
        if(n ==0) return 0;
        if(n<0) return INT_MIN;
        if(dp[n] != 0) return dp[n];
        int cutX = helper(n-x,x,y,z,dp);
        int cutY = helper(n-y,x,y,z,dp);
        int cutZ = helper(n-z,x,y,z,dp);
        return dp[n] = 1+max({cutX,cutY,cutZ});
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
         vector<int> dp(n+1,0);
         if(helper(n,x,y,z,dp) <0) return 0;
         return helper(n,x,y,z,dp);
    }
};