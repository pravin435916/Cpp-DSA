class Solution {
    // Input: s = "ABFCACDB"
    // Output: 2
    // Explanation: We can do the following operations:
    // - Remove the substring "ABFCACDB", so s = "FCACDB".
    // - Remove the substring "FCACDB", so s = "FCAB".
    // - Remove the substring "FCAB", so s = "FC".
    // So the resulting length of the string is 2.
    // It can be shown that it is the minimum length that we can obtain.
public:
    int minLength(string str) {
        stack<char> st;
        for (char ch : str) {
            if (!st.empty() && ((st.top() == 'A' && ch == 'B') ||
                                (st.top() == 'C' && ch == 'D'))) {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        return st.size();
    }
};