class Solution {
    public:
      vector<vector<int>> dp;
      int solve(int i,int n,vector<int> &price) {
          if(i==0) {
              return n * price[0];
          }
          if(dp[i][n] != -1) return dp[i][n];
          int nottake = 0+solve(i-1,n,price);
          int take = INT_MIN;
          int rodLen = i+1;
          if(rodLen <= n) {
              take = price[i] + solve(i,n-rodLen,price); // infinite supply of cuts
          }
          return dp[i][n] = max(take,nottake);
      }
      int cutRod(vector<int> &price) {
          // code here
          int n = price.size();
          dp.assign(n, vector<int>(n + 1, -1)); // dp[i][n]
          return solve(n-1,n,price);
      }
  };