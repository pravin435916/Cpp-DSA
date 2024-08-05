class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int ct = 0;
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        for (string s : words1) mp1[s]++;
        for (string s : words2) mp2[s]++;
        // Find words that occur exactly once in words1
        unordered_set<string> v1;
        for (auto x : mp1) {
            if (x.second == 1) {
                v1.insert(x.first);
            }
        }

        // Count how many of these words also occur exactly once in words2
        for (auto x : mp2) {
            if (x.second == 1 && v1.find(x.first) != v1.end()) {
                ct++;
            }
        }
        return ct;
    }
};