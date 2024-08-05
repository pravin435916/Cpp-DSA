#include <bits/stdc++.h>
using namespace std;
// top down (Recursive)
int fibo1(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    dp[n] = fibo1(n-1, dp) + fibo1(n-2, dp);
    return dp[n];
}
//bottom up (for loop) tabulation
int fibo2(int n) {
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main() {
    int n = 5;
    vector<int> dp(n+1, -1);
    cout << fibo1(n, dp) << endl;
    cout << fibo2(n) << endl;
    return 0;
}
