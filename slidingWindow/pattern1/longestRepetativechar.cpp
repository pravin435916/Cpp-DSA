class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int left =0;
            int right =0;
            int maxi = 0;
            unordered_map<char,int> mp;
    
            while(right < s.length()) {
                mp[s[right]]++;
    
                while(mp[s[right]] > 1) { // if repeatative char got shrink it
                    mp[s[left]]--;
                    left++;
                }
                maxi = max(maxi,right-left+1);
                right++; 
            }
            return maxi;
        }
    };
//     Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.