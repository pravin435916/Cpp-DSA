class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string prev = countAndSay(n-1);
        string ans = "";
        int i=0,j=0;
        while(j < prev.length()) {
            if(prev[i] == prev[j]) {
                j++;
            }else{
                int len = j-i; // 1 1 1 1 2 2 
                ans += to_string(len);
                ans += prev[i];
                i = j;
            }
        }
        // for last combination 1 1 1 1 2 2 
        int len = j-i;
        ans += to_string(len);
        ans += prev[i];
        return ans;
    }
};