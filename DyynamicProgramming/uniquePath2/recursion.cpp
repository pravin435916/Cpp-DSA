class Solution {
public:
    int helper(vector<vector<int>> &v,int i,int j) {
        if(i>=0 && j>=0 && v[i][j] == 1) return 0;  //additional case for obstacle
        if(i == 0 && j == 0) return 1;
        if(j<0 || i<0) return 0;
        int left = helper(v,i,j-1);
        int up = helper(v,i-1,j);
        return left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        return helper(v,n-1,m-1);
    }
};