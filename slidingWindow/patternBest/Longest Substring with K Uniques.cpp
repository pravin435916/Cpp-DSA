class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<int,int> mp;
        int l = 0;
        int maxi = -1;
        for(int r=0;r<s.length();r++) {
            mp[s[r]-'a']++;
            while(mp.size() > k) {
                mp[s[l]-'a']--;
                if(mp[s[l]-'a'] == 0) mp.erase(s[l]-'a');
                l++;
            }
            if(mp.size() == k) {
                maxi = max(maxi,r-l+1);
            }
        }
        return maxi;
    }
};