// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
class Solution {
    public:
        string minWindow(string s, string t) {
            unordered_map<char,int> mp;
            for(char ch : t) mp[ch]++;
    
            int left=0, n = s.length();
            int ct = 0;
            int tCt = t.length();
    
            int mini = INT_MAX;
            int minLen = INT_MAX;
            int minStart = 0;
    
            for(int right=0;right<n;right++) {
                if (mp[s[right]] > 0) ct++;
                mp[s[right]]--;
    
                while (ct == tCt) {
                    if(right-left+1 < minLen) {
                        minLen = right-left+1;
                        minStart = left;
                    }
                    mini = min(mini,ct);
                    mp[s[left]]++;
                    if (mp[s[left]] > 0) ct--;
                    left++;
                }
            }
    
            return minLen == INT_MAX ? "" : s.substr(minStart,minLen);
        }
    };