#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j) {
        if(i == 0 && j == 0) return grid[i][j];
        if(i<0 || j < 0) return INT_MAX;
        int left = helper(grid,i,j-1);
        int up = helper(grid,i-1,j);
        return grid[i][j] + min(left, up);
    }
    // top down DP
    int helper2(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
        // Base cases
        if (i < 0 || j < 0) return INT_MAX; // Out of bounds
        if (i == 0 && j == 0) return grid[i][j]; 
        //if already computed return it
        if (dp[i][j] != -1) return dp[i][j];
        // do stufff
        int left = helper2(grid, dp, i, j - 1);
        int up = helper2(grid, dp, i - 1, j);
        return dp[i][j] = grid[i][j] + min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // return helper(grid,n-1,m-1);
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return helper2(grid, memo, n - 1, m - 1);
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {2, 1, 5},
        {4, 2, 3},
        {6, 5, 4},
        {1, 1, 5}
        // if we start from end cell first move left -> left -> up -> up 
        // it recursively chooose minimum path of left and up and add into current cell 
    };
    int result = sol.minPathSum(grid);
    cout << "Minimum Path Sum: " << result << endl; // Output should be 7
    return 0;
}
