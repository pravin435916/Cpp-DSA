class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int maxLen = 0;
        int j=0;
        vector<int> count(256,0);
        // unordered_set<char> set;    //set unique
        while (j < s.length()) {
            while(count[s[j]] == 1) {
                count[s[i]] = 0;
                i++;
            }
            count[s[j]] = 1;
            // while (set.find(s[j]) != set.end()) {    //if got in set then remove first element a b a but a repeat 
            //     set.erase(s[i]);  //removed
            //     i++;  //move first pointer to next
            // }
            // set.insert(s[j]);  //insert
            maxLen = max(maxLen, j - i + 1);   //max len   (end - start + 1)
            j++;
        }
        return maxLen;
    }
};