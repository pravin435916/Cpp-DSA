// Input: s = "ababccc"
// Output: 5
// Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
// Example 2:

// Input: s = "aba"
// Output: 2
// Explanation: One way to split maximally is ['a', 'ba'].
// Example 3:

// Input: s = "aa"
// Output: 1
// Explanation: It is impossible to split the string any further.
class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        return solve(s, 0, set);
    }
    private:
    int solve(const string& s, int i, unordered_set<string>& set) {
        // Base case: If we reach the end of the string, return 0 (no more
        // substrings to add)
        if (i == s.size()) return 0;

        int maxCount = 0;

        // Try every possible substring starting from 'start'
        for (int j = i ; j < s.size(); ++j) {
            string substring = s.substr(i, j - i + 1);
            // If the substring is unique
            if (set.find(substring) == set.end()) {
                // Add the substring to the seen set
                set.insert(substring);
                // Recursively count unique substrings from the next position
                maxCount = max(maxCount, 1 + solve(s, j+1, set));
                // Backtrack: remove the substring from the seen set
                set.erase(substring);
            }
        }
        return maxCount;
    }
};