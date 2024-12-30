#include<iostream>
#include<vector>
using namespace std;
int helper(int i, int j, vector<vector<int>>& dp) {
    //base case
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;
    //if already computed return it
    if(dp[i][j] != -1) return dp[i][j];
    //do stuff
    int left = helper(i, j-1, dp);
    int up = helper(i-1, j, dp);
    //store in 2d dp
    return dp[i][j] = left + up;
}

int main() {
    int m =2, n=2;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout<<helper(m-1, n-1, dp);
}
