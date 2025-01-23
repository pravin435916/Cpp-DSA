class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        //  to store the count of servers in each row and column
        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);
        
        // 1: Count the number of servers in each row and column
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        // 2. check if 1 then check its rowcount or columncount is greater than 1
         int res = 0;
         for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1 &&  (rowCount[i] > 1 || colCount[j] > 1)) {
                    res++;
                }
            }
        }
        return res;


        // can use DFS too.
    }
};