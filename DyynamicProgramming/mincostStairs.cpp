class Solution {
    public:
     vector<int> dp;
      int solve(vector<int> &cost,int idx) {
          if(idx >= cost.size()) return 0;
          if(dp[idx] != -1) return dp[idx];
          
          int onestep = solve(cost,idx+1);
          int twostep = solve(cost,idx+2);
          
          return dp[idx] = cost[idx] + min(onestep,twostep);
      }
      int minCostClimbingStairs(vector<int>& cost) {
          int n = cost.size();
          dp.assign(n,-1);
          return min(solve(cost,0),solve(cost,1));  // minimum from index 1 or 0
      }
  };
// Input: cost = [10, 15, 20]
// Output: 15
// Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.
// Compare this snippet from DyynamicProgramming/minimumCostToReachEnd.cpp:
// // Given an array arr[] of size n, where arr[i] denotes the height of ith stone. Geek starts from stone 0 and from stone i, he can jump to stones i + 1, i + 2, … i +
// // k. The cost for jumping from stone i to stone j is abs(arr[i] – arr[j]). Find the minimum cost for Geek to reach the last stone.
