#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(int arr[], int n, vector<int>& dp) {
        // Base case: if we're at the first element, cost is zero
        if (n == 0) return 0;

        // Check if the result is already computed
        if (dp[n] != -1) return dp[n];

        // Cost to jump from the (n-1)th element to the nth element
        int first = abs(arr[n] - arr[n-1]) + solve(arr, n-1, dp);
        cout << "1 : " << first << endl;

        // Initialize second jump cost as a large value
        int second = INT_MAX;

        // If possible, calculate the cost to jump from the (n-2)th element to the nth element
        if (n-2 >= 0) {
            second = abs(arr[n] - arr[n-2]) + solve(arr, n-2, dp);
            cout << "2 : " << second << endl;
        }

        // Store the result in dp array and return it
        return dp[n] = min(first, second);
    }
};

int main() {
    Solution sol;
    int arr[] = {5, 10, 20, 30, 10}; // Example input
    int n = sizeof(arr)/sizeof(arr[0]) - 1; // Last index
    
    // Initialize dp array with -1 (indicating uncomputed states)
    vector<int> dp(n + 1, -1);
    
    // Output the minimum cost
    cout << sol.solve(arr, n, dp) << endl; 
    return 0;
}
