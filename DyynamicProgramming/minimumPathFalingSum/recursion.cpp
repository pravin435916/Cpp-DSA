class Solution {
public:
    int helper(vector<vector<int>>& v,int i,int j) {
        int n = v.size();
        if(j<0 || j>=n) return INT_MAX;
        if(i == n-1) return v[n-1][j];
        int down = helper(v,i+1,j);
        int downRight = helper(v,i+1,j+1);
        int downLeft = helper(v,i+1,j-1);
        return v[i][j] + min({down,downRight,downLeft});
    }
    int minFallingPathSum(vector<vector<int>>& v) {
        int mini = INT_MAX;
        int n = v.size();
        for(int col=0;col<n;col++) {
            mini = min(mini,helper(v,0,col));
        }
        return mini;
    }
};