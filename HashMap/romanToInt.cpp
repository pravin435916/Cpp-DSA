class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMp = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int res = 0;

    // Iterate through the string
    for (int i = 0; i < s.length(); i++) {
        // Check for a subtractive combination
        if (i + 1 < s.length() && romanMp[s[i]] < romanMp[s[i + 1]]) {
            res += romanMp[s[i + 1]] - romanMp[s[i]];
            i++; // Skip the next character
        } else {
            res += romanMp[s[i]];
        }
    }

    return res;
    }
};