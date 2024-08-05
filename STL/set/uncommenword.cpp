class Solution {
public:
vector<string> split(vector<string> &v,string &s1) {
    size_t start = 0;
    size_t end = s1.find(' ');
    while (end != string::npos) {
        v.push_back(s1.substr(start, end - start));
        start = end + 1;
        end = s1.find(' ', start);
    }
    // Add the last word
    v.push_back(s1.substr(start));
    return v;
}
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> v;
        vector<string> res;
        vector<string> v1 = split(v,s1);
        v1 = split(v,s2);
        unordered_map<string,int> mp;
        for(string x : v1) mp[x]++;
        for(auto x : mp) {
            if(x.second == 1) {
                res.push_back(x.first);
            }
        }
        return res;
    }
};