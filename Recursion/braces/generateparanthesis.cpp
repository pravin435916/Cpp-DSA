class Solution {
public:
    void helper(int n, vector<string>& res, int open, int close, string ans) {
        if (ans.length() == 2 * n) { // at most max 2*n  braces
            res.push_back(ans);
            return;
        }
        if (open < n) {
            helper(n, res, open + 1, close, ans + '(');
        }
        if (close < open) {
            helper(n, res, open, close + 1, ans + ')');
        }
    }
    // Tc for this Function :- o(2n)
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (!st.empty() && st.top() == '(' && ch == ')') {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        return st.empty();
    }
    // Tc for this Function :- o(2^2n)    2*n traverse     for each position we are traverse 2 direction
    void helper2(int n, vector<string>& res, string cur) {
        if (cur.length() == 2 * n) { // at most max 2*n  braces
            if (isValid(cur)) {      // Check if the current sequence is valid
                res.push_back(cur);
            }
            return;
        }
        cur += '(';
        helper2(n, res, cur);

        cur.pop_back();

        cur += ')';
        helper2(n, res, cur);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        // helper(n,res,0,0,"");
        helper2(n, res, "");  // total TC :- o(2n * 2^2n)    SC:- o(depth of stack space)
        return res;
    }
};