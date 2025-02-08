// Given an array arr[] of size n, where arr[i] denotes the height of ith stone. Geek starts from stone 0 and from stone i, he can jump to stones i + 1, i + 2, … i + k. The cost for jumping from stone i to stone j is abs(arr[i] – arr[j]). Find the minimum cost for Geek to reach the last stone.

// Example:

// Input: k = 3, arr[]= [10, 30, 40, 50, 20]
// Output: 30
// Explanation: Geek will follow the path 1->2->5, the total cost would be |10-30| + |30-20| = 30, which is minimum.
public:
   int solve(int i,int n,int k,vector<int>& height,vector<int> &dp) {
        if(i == n-1)  return 0;
        if(dp[i] != -1) return dp[i];
        int minCost = INT_MAX;
        for(int j=1;j<=k;j++) {
            if(i+j < n) {
               minCost = min(minCost,solve(i+j,n,k,height,dp) + abs(height[i] - height[i+j]));
            }
        }
        return dp[i] = minCost;
    }
    int minimizeCost(int k, vector<int>& height) {
        int n = height.size();
        vector<int> dp(n,-1);
        return solve(0,n,k,height,dp);
    }