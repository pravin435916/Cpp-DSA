class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            if(mp.find(arr[i]) != mp.end()) {
                if((i - mp[arr[i]]) <= k) return true;
            }else{
                mp[arr[i]] = i;
            }
        }
        return false;
    }
};