class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        // Create a dp array of size n x m, initialized to 0
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: if the starting cell has an obstacle, return 0
        if (v[0][0] == 1) return 0;

        // Initialize the starting position
        dp[0][0] = 1;

        // Fill the dp array
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Skip the starting cell as it's already initialized
                if (i == 0 && j == 0) continue;

                // If there's an obstacle at (i, j), no paths can pass through
                if (v[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    // Calculate paths from the top (up) and left (left)
                    if (i > 0) dp[i][j] += dp[i-1][j];
                    if (j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }

        // The answer will be the value at the bottom-right corner
        return dp[n-1][m-1];
    }
};
