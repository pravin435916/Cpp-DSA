class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &v)
    {
        int n = v.size();
        int m = v[0].size();
        vector<bool> row(n,false);
        vector<bool> col(m,false);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(v[i][j] == 1) {
                    //mark its row and col true
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        //modify matrix if their row or col is true then print 1
          for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(row[i] || col[j]) {
                    v[i][j] = 1;
                }
            }
        }
    }
};
// Input:
// matrix[][] = {{1, 0},
//               {0, 0}}
// Output: 
// 1 1
// 1 0 
// Explanation:
// Only cell that has 1 is at (0,0) so all 
// cells in row 0 are modified to 1 and all 
// cells in column 0 are modified to 1.

// Example 2:

// Input:
// matrix[][] = {{ 1, 0, 0},
//               { 1, 0, 0},
//               { 1, 0, 0},
//               { 0, 0, 0}}
// Output: 
// 1 1 1
// 1 1 1
// 1 1 1
// 1 0 0 
// Explanation:
// The position of cells that have 1 in
// the original matrix are (0,0), (1,0)
// and (2,0). Therefore, all cells in row
// 0,1,2 are and column 0 are modified to 1. 