class Solution {
//     order ="cba"
//     s = "abcd"
//    Output = "cbad"
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(char ch : s) {
            mp[ch]++;
        }
        string ans = "";
        for(char ch : order) {  //check order char is present in string
            while(mp[ch]) { //if yes then first add those charcter 
               ans+=ch;
               mp[ch]--;
            }
        }
        for(auto x : mp) {  //for remaining charcter
            while(x.second) {    //if any remaining
                ans+=x.first;   //push
                x.second--;  //decrease frequency
            }
        }
        return ans;
    }
};