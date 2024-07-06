class Solution {
//     s ="cccaaa"
// Output = "aaaccc"
public:
    string frequencySort(string str) {
        unordered_map<char,int> mp;
        //store frequency
        for(char ch : str) {
            mp[ch]++;
        }
        string ans;
        //convert map into vector
        vector<pair<char, int>> v(mp.begin(), mp.end());

        //sort frequency
        sort(v.begin(), v.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; // Sort by frequency (second element of pairs)
        });
        //most frequency elements come first
        for (auto x : v) {
            while (x.second > 0) {
                ans += x.first;
                x.second--;
            }
        }
        return ans;
    }
};