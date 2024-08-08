int minimumEnergy(vector<int>& arr, int n) {
        if (n == 0) return 0;

        vector<int> dp(n, INT_MAX);
        dp[0] = 0; // Base case: Cost to reach the first element is 0
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + abs(arr[i] - arr[i - 1]);
            if (i > 1) {
                dp[i] = min(dp[i], dp[i - 2] + abs(arr[i] - arr[i - 2]));
            }
        }
        return dp[n - 1];
    }