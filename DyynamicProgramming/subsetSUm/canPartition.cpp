class Solution {
public:
// simple logic check for totalsum/2 subset if total sum is even otherwise false
   vector<vector<int>> dp;

    bool solve(int idx, int sum, int target, vector<int>& arr) {
        if (sum == target) return true;
        if (idx >= arr.size() || sum > target) return false;
        if (dp[idx][sum] != -1) return dp[idx][sum];

        bool take = solve(idx + 1, sum + arr[idx], target, arr);
        bool nottake = solve(idx + 1, sum, target, arr);

        return dp[idx][sum] = take || nottake;
    }
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int total = accumulate(arr.begin(),arr.end(),0);
        if(total % 2 !=0) return false;  // odd sum cant partition
        int target = total/2;
        dp.resize(n, vector<int>(target + 1, -1));
        return solve(0,0,target,arr);
    }
};