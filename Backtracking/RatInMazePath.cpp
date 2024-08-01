class Solution {
  public:
    void helper(vector<vector<int>> &v,int sr,int sc,int er,int ec,vector<string> &res,string path) {
        // if out of bound or 0 then return by here
        if (sr > er || sc > ec || sr < 0 || sc < 0 || v[sr][sc] == 0) return;
        //if reach at last position push ans
        if (sr == er && sc == ec) {
        res.push_back(path);
        return;
    }
    //mark it 0
     v[sr][sc] = 0;
    
    // Move right
    helper(v, sr, sc + 1, er, ec,res, path + "R");
    // Move down
    helper(v, sr + 1, sc, er, ec,res, path + "D");
    // Move left
    helper(v, sr, sc - 1, er, ec,res, path + "L");
    // Move up
    helper(v, sr - 1, sc, er, ec,res, path + "U");
    
    // (backtrack)
    v[sr][sc] = 1;
    }
    vector<string> findPath(vector<vector<int>> &v) {
        vector<string> res;
        int n = v.size();
        int m = v[0].size();
        helper(v,0,0,n-1,m-1,res,"");
        return res;
    }
};