// Given an array arr[] consisting of positive integers, your task is to find the length of the longest subarray that contains at most two distinct integers.
class Solution {
  public:
    int totalElements(vector<int> &s) {
        // code here
        unordered_map<int,int> mp;
        int l = 0;
        int maxi = -1;
        for(int r=0;r<s.size();r++) {
            mp[s[r]]++;
            while(mp.size() > 2) {
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            if(mp.size() <= 2) {
                maxi = max(maxi,r-l+1);
            }
        }
        return maxi;
    }
};