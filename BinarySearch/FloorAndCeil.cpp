//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int nums[], int n, int target) {
       //unsorted array so sort it first
       sort(nums,nums+n);
        int low = 0;
        int high = n-1;
        int f = -1;
        int c = -1;
        while(low <= high) {
            int mid = low + (high - low) /2;
            if (nums[mid] == target) {
            f = c = nums[mid];
            break; // Found exact match, both floor and ceil are the same
            }else if(nums[mid] <= target) {
                f = nums[mid];
                low = mid+1;
            }else{
                c = nums[mid];
                high = mid-1;
            }
        }
        return {f,c};
}
// Input:
// N = 8, X = 10
// Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
// Output: 9 -1
// Explanation:
// Floor of 10 is 9 but ceil of 10 is not 
// possible.

// Input:
// N = 8, X = 7
// Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
// Output: 6 8
// Explanation:
// Floor of 7 is 6 and ceil of 7 
// is 8.