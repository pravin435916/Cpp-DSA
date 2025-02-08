#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
int solve(int i,int n,vector<int>& height) {
    if(i == n-1)  return 0;
    int case1 = solve(i+1,n,height) + abs(height[i] - height[i+1]);
    int case2 = (i+2 <  n ) ?solve(i+2,n,height) + abs(height[i] - height[i+2]) : INT_MAX;
    return min(case1,case2);
}
int minCost(vector<int>& height) {
    int n = height.size();
    return solve(0,n,height);
}
};

int main() {
    Solution sol;
    vector<int> arr = {5,10, 20, 30, 10}; // Example input
    // cout<<n<<endl;
    cout << sol.minCost(arr) << endl; // Output the minimum cost
    return 0;
}
