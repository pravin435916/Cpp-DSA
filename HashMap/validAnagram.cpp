// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        unordered_map<char,int> mp;
        for(char ch : s) {
            mp[ch]++;     //store frequency
        }
        for(char ch : t) {
            if(mp.find(ch) == mp.end() || mp[ch] == 0) {    //if not get or thast charcter freq. is 0
                return false;
            }
            mp[ch]--;   //if get then remove
        }
       return true;

        //logic 2 
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s == t) return true;
        // else return false;
    }
};