// 1. Rotten Oranges Simple concept
// 2 -> rotten
// 1 -> fresh
// 0 -> empty
// print minimum no. of steps to rotten all oranges
// after completing all steps if any orange left fresh mean 1 then -1
class Solution {
int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, -1, 1};
public:
    queue<pair<int, int>> q;  //make queue for row and col
    bool isvalid(int x, int y, vector<vector<int>>& grid,vector<vector<bool>>& vis,int m,int n) {
        if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == 1) return true;
        else return false;
    }
    int bfs(vector<vector<int>>& grid,vector<vector<bool>> &vis,int m,int n) {
        int step = -1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                pair<int, int> top = q.front();
                int x = top.first;  //row
                int y = top.second; // col
                q.pop();
                for(int k=0; k<4; k++) {  //check for four sides
                    int tx = x + fx[k];  //new row
                    int ty = y + fy[k];  // new col
                    if(isvalid(tx, ty, grid,vis,m,n)) {
                        vis[tx][ty] = true;
                        q.push({tx, ty});
                    }
                }
            }
            step++;
        }
        return step;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        int ans = max(0, bfs(grid,vis,m,n));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(!vis[i][j] and grid[i][j] == 1) return -1;
        return ans;
    }
};