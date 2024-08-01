class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &v) {
        int n = v.size();
        int m = v[0].size();
        int maxi = 0;
        int row = -1;
        for(int i=0;i<n;i++) {
            int ct=0;
            for(int j=0;j<m;j++) {
                if(v[i][j] == 1) {
                    ct++;
                }
            }
            if (ct > maxi) {
                maxi = ct;
                row = i;
            }
        }   
        return row;
    }
};