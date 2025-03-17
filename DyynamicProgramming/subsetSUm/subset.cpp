class Solution {
    public:
    vector<vector<int>> dp;
    bool solve(vector<int> &arr,int sum, int i) {
        if(sum == 0) return true;
        if(i>=arr.size() || sum < 0) return false;
        if(dp[i][sum] != -1) return dp[i][sum];
        bool take = solve(arr,sum-arr[i],i+1);
        bool  nottake = solve(arr,sum,i+1);
        return dp[i][sum] = take || nottake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        dp.assign(n,vector<int> (sum+1,-1));
        return solve(arr,sum,0);
    }
  };

//   Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
// Output: true 
// Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.