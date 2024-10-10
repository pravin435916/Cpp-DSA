//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// Input: arr = [1, 1, 2, 2, 2, 1]
// Output: 5
// Explanation: distance for 1 is: 5-0 = 5, distance for 2 is : 4-2 = 2, So max distance is 5.
// Input: arr = [3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2]
// Output: 10
// Explanation: maximum distance for 2 is 11-1 = 10, maximum distance for 1 is 4-2 = 2 ,maximum distance for 4 is 10-5 = 5, So max distance is 10.
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        int maxi = INT_MIN;
        int i=0;
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            if(mp.find(arr[i]) != mp.end()) {  // means got
                int distance = i - mp[arr[i]];
                maxi = max(maxi,distance);
            }else{
                mp[arr[i]] = i;
            }
        }
        return maxi;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}