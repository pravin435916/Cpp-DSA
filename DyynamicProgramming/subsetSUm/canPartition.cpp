class Solution {
    public:
    vector<vector<int>> dp;
      bool solve(int idx,int sum,int target,vector<int> &arr) {
          if(sum == target) {
              return true;
          }
          
          if(idx >= arr.size() || sum > target) return false;
          if (dp[idx][sum] != -1) return dp[idx][sum];
          bool take = solve(idx+1,sum+arr[idx],target,arr);
          bool nottake = solve(idx+1,sum,target,arr);
          return dp[idx][sum] = take || nottake;
      }
      bool isSubsetSum(vector<int>& arr, int target) {
          int n =arr.size();
          dp.resize(n, vector<int>(target + 1, -1));
          return solve(0,0,target,arr);
      }
  };