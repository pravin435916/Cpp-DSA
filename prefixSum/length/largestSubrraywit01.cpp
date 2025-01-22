#include <vector>
#include <map>
using namespace std;

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n = arr.size();
        for(int i=0;i<n;i++) {
            if(arr[i] == 0) arr[i] = -1;
        }
        int k=0;
        int sum = 0,maxi =0;
        map<int,int> mp;
        for(int i=0;i<n;i++) {
            sum += arr[i];
            if(sum == k) {
                maxi = max(maxi,i+1);
            }
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
            if(mp.find(sum-k) != mp.end()) {
               maxi = max(maxi,i-mp[sum-k]);
            }
        }
        return maxi;
    }
};