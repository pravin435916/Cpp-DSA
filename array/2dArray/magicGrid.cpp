class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        // Iterate over each possible top-left corner of a 3x3 subgrid
        for(int i = 0; i <= n - 3; i++) {
            for(int j = 0; j <= m - 3; j++) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
    private:
    bool isMagicSquare(const vector<vector<int>>& grid, int row, int col) {
        // Expected magic sum for a 3x3 grid
        const int magicSum = 15;
         // Check if all elements are distinct and in the range [1, 9]
        vector<bool> unique(10, false); // To track numbers 1 to 9
        for (int i = row; i < row + 3; ++i) {
            for (int j = col; j < col + 3; ++j) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || unique[num]) {
                    return false; // Not unique or not in range 1-9
                }
                unique[num] = true;
            }
        }
        
        // Check row sums
        for (int i = 0; i < 3; ++i) {
            int rowSum = 0;
            for (int j = 0; j < 3; ++j) {
                rowSum += grid[row + i][col + j];
            }
            if (rowSum != magicSum) return false;
        }

        // Check column sums
        for (int j = 0; j < 3; ++j) {
            int colSum = 0;
            for (int i = 0; i < 3; ++i) {
                colSum += grid[row + i][col + j];
            }
            if (colSum != magicSum) return false;
        }

        // Check diagonal sums
        int diag1Sum = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diag2Sum = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
        if (diag1Sum != magicSum || diag2Sum != magicSum) return false;
        return true;
    }
};