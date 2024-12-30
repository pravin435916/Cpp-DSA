// 2. Time Complexity of the Top-Down Approach (with memoization):
// In the top-down recursive approach with memoization, we store the result of each subproblem in a memo array. This avoids redundant calculations since each subproblem is computed only once.

// The memoization ensures that each position triangle[row][col] is processed only once, and its result is reused for future calculations.
// The size of the memo array is proportional to the number of elements in the triangle, which is n(n + 1) / 2 (the total number of elements in the triangle), where n is the number of rows.
// Thus, the time complexity of the top-down approach with memoization is:

// O(n²), since we visit each element of the triangle once and perform constant time operations for each element.
class Solution {
public:
    // tc : o(n^2)
    int helper(int i,int j,vector<vector<int>>& tri,vector<vector<int>>& dp){
       if(i == tri.size()-1) return tri[i][j]; // if row is last return result
       if(dp[i][j] != -1) return dp[i][j];  //already computed result
       int down = helper(i+1,j,tri,dp); // for down
       int downRight = helper(i+1,j+1,tri,dp); // for right diagonal
       return dp[i][j] = tri[i][j] + min(down,downRight); // that particular element + min(other)
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0,0,tri,dp);
    }
};