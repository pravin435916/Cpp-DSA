#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(int arr[], int n) {
        // Base case: if we're at the first element, cost is zero
        if (n == 0) return 0;

        // Cost to jump from the (n-1)th element to the nth element
        int first = abs(arr[n] - arr[n-1]) + solve(arr, n-1);
        cout<<"1 : "<<first<<endl;
        // Initialize second jump cost as a large value
        int second = INT_MAX;

        // If possible, calculate the cost to jump from the (n-2)th element to the nth element
        if (n-2 >= 0) {
            second = abs(arr[n] - arr[n-2]) + solve(arr, n-2);
            cout<<"2 : "<<second<<endl;

        }
        
        // Return the minimum of the two possible costs
        return min(first, second);
    }
};

int main() {
    Solution sol;
    int arr[] = {5,10, 20, 30, 10}; // Example input
    int n = sizeof(arr)/sizeof(arr[0]) - 1; // Last index
    // cout<<n<<endl;
    cout << sol.solve(arr, n) << endl; // Output the minimum cost
    return 0;
}
