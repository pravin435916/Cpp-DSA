int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    // Base Case: dp[n][buy] = 0 (already initialized to 0)
     for(int idx=n-1;idx>=0;idx--) {
         for (int buy = 0; buy <= 1; buy++) {
             if (buy) {
                 int buys = -prices[idx] + dp[idx+1][0];
                 int notbuy = 0 + dp[idx+1][1];
                 dp[idx][buy] = max(buys, notbuy);
             } else {
                 int sell = prices[idx] + dp[idx+1][1];
                 int notsell = 0 + dp[idx+1][0];
                 dp[idx][buy] = max(sell, notsell);
             }
         }
     }
     return dp[0][1]; // Start from day 0 with the ability to buy
}