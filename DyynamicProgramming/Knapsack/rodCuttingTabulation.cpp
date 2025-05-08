#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int rodCutting(int price[], int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    // Base case: only using length 1
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j * price[0];
    }

    for (int i = 1; i < n; i++) {
        int rodLength = i + 1;
        for (int j = 0; j <= n; j++) {
            int notTake = dp[i - 1][j];
            int take = INT_MIN;
            if (rodLength <= j)
                take = price[i] + dp[i][j - rodLength];
            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n - 1][n];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);

    cout << "Maximum Obtainable Value is " << rodCutting(price, n) << endl;

    return 0;
}
