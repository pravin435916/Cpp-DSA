class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x : nums) {
            mp[x]++;
        }
        vector<pair<int, int>> helper;
         //push num and its frequency
        for (auto x : mp) {
            helper.push_back({x.first, x.second}); 
         }
         //sort by its frequency
        sort(helper.begin(), helper.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });
        //now got sorted
        vector<int> res;
        for (auto x : helper) {
            int freq = x.second;
            while (freq--) {  //push all its frequnecy
                res.push_back(x.first);
            }
        }
        return res;
    }
};