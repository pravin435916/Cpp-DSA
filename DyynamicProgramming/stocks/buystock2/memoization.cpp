
// 122. Best Time to Buy and Sell Stock II

class Solution {
    public:
    vector<vector<int>> dp;
    int solve(int idx, int buy, int n, vector<int>& prices) {
        if (idx == n)  return 0;
        int profit = 0;
        if(dp[idx][buy] != -1) return dp[idx][buy]; 
        // for this how i decided idx and buy ? this two is changing 
        // buy is 0 or 1 so its size is 2
        if (buy) {
            int buys = -prices[idx] + solve(idx + 1, 0, n, prices);
            // has -prices[idx] because when we decide to buy a stock at index idx, we are spending money. In a profit maximization problem, spending money is considered a negative value.
                int notbuy = 0 + solve(idx + 1, 1, n, prices);
                profit = max(buys,notbuy);
            } else {
                int sell = prices[idx] + solve(idx + 1, 1, n, prices);
                int notsell = 0 + solve(idx + 1, 0, n, prices);
                profit = max(sell,notsell);
            }
            return dp[idx][buy] = profit;
        }
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            dp.assign(n,vector<int> (2,-1));
            return solve(0, 1, n, prices); 
            //1 means buy 
        }
    };