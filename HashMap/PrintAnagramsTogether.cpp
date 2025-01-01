class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
       unordered_map<string,vector<string>> mp; //sorted , unsorted strings 
       
       for(string x : arr) {
           string temp = x;
           sort(temp.begin(),temp.end());
           mp[temp].push_back(x); //push string into vector
       }
       vector<vector<string>> res;
       for(auto& it : mp) {
           res.push_back(it.second);
       }
       return res;
    }
};