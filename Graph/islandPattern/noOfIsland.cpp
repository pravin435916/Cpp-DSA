class Solution{
private:
    bool dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1 || grid[i][j] != '1') {
            return false; // if neighbours is not 1 and out of boundry then  false
        }
        grid[i][j] = '0'; // if check then Mark as visited and check for another 1
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        return true;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ct = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    if (dfs(grid, i, j))
                        ct++;
                }
            }
        }
        return ct;
    }
};