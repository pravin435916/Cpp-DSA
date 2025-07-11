// Aggressive Cows
// You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// Examples :

// Input: stalls[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at stalls[0], 
// the second cow can be placed at stalls[2] and 
// the third cow can be placed at stalls[3]. 
// The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isPossibleToPlace(vector<int> &stalls, int k,int mid) {
        int n = stalls.size();
        int cow = 1;
        int lastStall = stalls[0];
        for(int i=1;i<n;i++) {
            if(stalls[i] - lastStall >= mid) {
                cow++;
                lastStall = stalls[i];
            }
            if(cow == k) return true; 
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int res = 0;
        int n = stalls.size();
        if (k > n) return -1;
        sort(stalls.begin(),stalls.end());
        int low = 1;
        int high = stalls[n - 1] - stalls[0];
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(isPossibleToPlace(stalls,k,mid)) {
                res = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends