class Solution {
public:
void helper(int n,vector<string> &res,int open,int close,string ans) {
     if (ans.length() == 2*n) { //at most max 2*n  braces
            res.push_back(ans);
            return;
        }
        if (open < n) {
            helper(n,res,open+1,close, ans + '(');
        }
        if(close < open) {
            helper(n,res,open,close+1, ans + ')');
        }
}
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n,res,0,0,"");
        return res;
    }
};