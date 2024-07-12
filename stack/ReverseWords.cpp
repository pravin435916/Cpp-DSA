class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' && temp != "") {
                st.push(temp);
                temp = "";
            } else if (s[i] == ' ' && temp == "")
                continue;
            else
                temp += s[i];
        }
        if (temp != "")
            st.push(temp);
        while (!st.empty()) {
            res += st.top();
            st.pop();
            if (!st.empty()) {
                res += " ";
            }
        }
        return res;
    }
};