// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int left=0,res=0;
            int n = s.length();
            int abcCount = 0;
            // simple dry run 
            vector<int> count(3,0);
            for(int right=0;right<n;right++) {
                count[s[right]-'a']++;
    
                while(count[0] > 0 && count[1] > 0 && count[2] > 0) {
                    res += n-right;
                    count[s[left]-'a']--;
                    left++;
                }
            }
            return res;
        }
    };