#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& mat, int n, int m) {
    if (j < 0 || j >= m) return 0; // Out of bounds
    if (i == n - 1) return mat[i][j]; // Base case: last row
    
    if (dp[i][j] != -1) return dp[i][j]; // Return memoized result
    
    int down = solve(i + 1, j, dp, mat, n, m);
    int leftDiagonal = (j > 0) ? solve(i + 1, j - 1, dp, mat, n, m) : 0;
    int rightDiagonal = (j < m - 1) ? solve(i + 1, j + 1, dp, mat, n, m) : 0;
    
    return dp[i][j] = mat[i][j] + max({down, leftDiagonal, rightDiagonal});
}

int maximumPath(vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 0) return 0;
    
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table for memoization
    
    int maxi = 0;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, solve(0, j, dp, mat, n, m));
    }
    
    return maxi;
}

int main() {
    vector<vector<int>> mat = {
        {10, 10, 2, 0, 20, 4},
        {1, 0, 0, 30, 2, 5},
        {0, 10, 4, 0, 2, 0},
        {1, 0, 2, 20, 0, 4}
    };
    cout << "Maximum Path Sum: " << maximumPath(mat) << endl;
    return 0;
}
