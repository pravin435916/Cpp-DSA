class Solution {
    public:
    int knapSackHelper(int capacity, vector<int> &val, vector<int> &wt,vector<vector<int>> &dp,int n) {
    
          if(n == 0 || capacity == 0 ) {
              return 0;
          }
          if(dp[n][capacity] != -1) return dp[n][capacity];
          
          if(wt[n-1] > capacity) {
              return dp[n][capacity] = knapSackHelper(capacity,val,wt,dp,n-1);
          }
          int take = val[n-1] + knapSackHelper(capacity - wt[n-1],val,wt,dp,n-1);
          int nottake = knapSackHelper(capacity,val,wt,dp,n-1);
          return dp[n][capacity] = max(take,nottake);
    }
    
      // Function to return max value that can be put in knapsack of capacity.
      int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
          int n = val.size();
          vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
          return knapSackHelper(capacity, val, wt,dp, n);
      }
      
  };