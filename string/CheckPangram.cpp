class Solution {
// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
// Explanation: sentence contains at least one of every letter of the English alphabet.
// Example 2:

// Input: sentence = "leetcode"
// Output: false
public:
    bool checkIfPangram(string s) {
        vector<bool> alpha(26, 0);
        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            alpha[idx] = 1; //mark present
        }
        for (int i = 0; i < 26; i++) {
            if (alpha[i] == 0) // if any 0 found then not all charcter present in it
                return false;
        }
        return true;
    }
};