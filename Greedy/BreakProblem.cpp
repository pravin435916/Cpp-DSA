class Solution {
    public:
        string breakPalindrome(string s) {
            if (s.length() < 2) return "";
            for (int i = 0; i < s.length() / 2; i++) {
                if(s[i] != 'a') {
                    s[i] = 'a';
                    return s;
                }
            }
            s[s.length()-1] = 'b';
            return s;
        }
    };