class Solution {
    private:
    //dfs
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1 || grid[i][j] != 0) {
            return false; // if neighbours is not 0 and out of boundry then  false
        }
        grid[i][j] = 1; // if check then Mark as visited and check for another 1
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        return true;
    }
public:
// tips for symbol problem always try to convert in number so we can compute
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> mat(n*3,vector<int>(m*3,0));
        // fill matrix according to slashes
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '/') {
                    mat[i*3][j*3+2] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3] = 1;
                }else if(grid[i][j] == '\\') {
                    mat[i*3][j*3] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3+2] = 1;
                }
            }
        }
        // Now Apply dfs on matrix same as no. of islands
        int ct = 0;
        int mi = mat.size();
        int ni = mat[0].size();
        for (int i = 0; i < mi; i++) {
            for (int j = 0; j < ni; j++) {
                if (mat[i][j] == 0) {
                    if (dfs(mat, i, j))
                        ct++;
                }
            }
        }
        return ct;
    }
};