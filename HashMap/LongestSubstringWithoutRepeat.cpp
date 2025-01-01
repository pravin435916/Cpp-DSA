class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; 
        int maxlen = 0;
        int left = 0;  

        for (int i = 0; i < s.length(); ++i) {
            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= left) { 
                // if mil gya 
                left = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            maxlen = max(maxlen, i - left + 1);
        }

        return maxlen;
    }
};