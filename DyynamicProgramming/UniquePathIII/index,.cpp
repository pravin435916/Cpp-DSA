class Solution {
    public:
    int m,n;
    int obstacles =0;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int uniquePathsIII(vector<vector<int>>& grid) {
            int res =0;
            m = grid.size();
            n = grid[0].size();
            int start_x=0,start_y=0;
            for(int i=0;i<m;i++) {
                for(int j=0;j<n;j++) {
                    if(grid[i][j] == 0) {
                        obstacles++;
                    }
                    if(grid[i][j] == 1) {  //
                        start_x = i;
                        start_y = j;
                    }
                }
            }
            obstacles++;
    
            solve(grid,start_x,start_y,obstacles,0,res);
            return res;
        }
        private:
        void solve(vector<vector<int>>& grid,int i,int j,int obstacles,int count,int &res) {
            if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == -1) {
                return;
            }
            if(grid[i][j] == 2) {
                if(count == obstacles) {
                   res++;
                }
                return;
            }
            grid[i][j] = -1; //marked as visited
            for(vector<int> &dir : directions) {
                int new_i = i+dir[0];
                int new_j = j+dir[1];
                solve(grid,new_i,new_j,obstacles,count+1,res);
            }
            grid[i][j] = 0; //backtrack
        }
    };