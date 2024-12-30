
// Input: grid = 
// [[2,4,3,5],
//  [5,4,9,3],
//  [3,4,2,11],
//  [10,9,13,15]]
// Output: 3
// Explanation: We can start at the cell (0, 0) and make the following moves:
// - (0, 0) -> (0, 1).
// - (0, 1) -> (1, 2).
// - (1, 2) -> (2, 3).
// It can be shown that it is the maximum number of moves that can be made.
class Solution {
public:
    const int dirs[3] = {-1, 0, 1};
    int DFS(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp) {
        int M = grid.size(), N = grid[0].size();
        if (dp[i][j] != -1)  return dp[i][j]; //check if already calculated
        int maxi = 0;
        for(int dir : dirs) {
            int newRow = i+dir,newCol = j+1; // find new row new col
            //check all conditions
            if(newRow >= 0 && newCol >= 0 && newRow < M && newCol < N && grid[i][j] < grid[newRow][newCol]) {
                maxi = max(maxi,1+DFS(newRow,newCol,grid,dp));
            }
        }
        return dp[i][j] = maxi;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> dp(M, vector<int>(N, -1));
        int maxi = 0;
        for (int i = 0; i < M; i++) {
            int movesRequired = DFS(i, 0, grid, dp);
            maxi = max(maxi, movesRequired);
        }
        return maxi;
    }
};