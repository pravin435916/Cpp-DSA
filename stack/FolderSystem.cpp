class Solution {
public:
    // int minOperations(vector<string>& logs) {
    //     int ct = 0;
    //     for (string x : logs) {
    //         if (x == "./") ct += 0;
    //         else if (x == "../") {
    //             if (ct > 0) {
    //                 ct -= 1;
    //             }
    //         } else ct += 1;
    //     }
    //     return ct > 0 ? ct : 0;
    // }
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(string x : logs) {
            if(x == "../") {
                if( !st.empty()) st.pop();
            }
            else if( x != "./") {
            st.push(x);
            }
        }
        return st.size();
    }
};