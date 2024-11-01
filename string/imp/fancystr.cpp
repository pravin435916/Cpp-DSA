class Solution {
public:
    string makeFancyString(string s) {
        int ct = 1;
        string res = "";
        res+=s[0];
        for (int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) {
                ct++;
            }else{
                ct = 1;
            }
            if(ct < 3) {
                res += s[i];
            }
        }
        return res;

        // stack<char> st;
        // int ct = 0;
        // for (int i = 0; i < s.length(); i++) {
        //     char cur = s[i];
        //     if (st.size() >= 2) {
        //         char top1 = st.top();
        //         st.pop();
        //         char top2 = st.top();
        //         st.push(top1);
        //         if (cur == top1 && cur == top2)
        //             continue;
        //     }

        //     st.push(cur);
        // }
        // string result;
        // while (!st.empty()) {
        //     result += st.top();
        //     st.pop();
        // }
        // reverse(result.begin(), result.end());
        // return result;
    }
};