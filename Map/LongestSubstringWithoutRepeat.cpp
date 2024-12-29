class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp; 
        int maxlen = 0;
        int left = 0;  

        for (int right = 0; right < s.length(); ++right) {
            if (mp.find(s[right]) != mp.end() && mp[s[right]] >= left) { 
                // if mil gya 
                left = mp[s[right]] + 1;
            }
            mp[s[right]] = right;
            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};