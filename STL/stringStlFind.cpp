class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m =needle.length();
        if(m > n) return -1;
        size_t pos = haystack.find(needle);
        // Check if the substring was found
        if (pos != string::npos) {
            return (int)pos; // Cast size_t to int
        } else {
            return -1;
        }
        // for (int i = 0; i <= n - m; i++) {
        //     if (haystack.substr(i,m) == needle) {
        //         return i;
        //     }
        // }
        return -1;        
    }
};