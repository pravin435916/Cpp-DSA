#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcsHelper(const string &X, const string &Y, int m, int n, vector<vector<int>> &memo) {
    if (m == 0 || n == 0)
        return 0;

    if (memo[m][n] != -1)
        return memo[m][n];

    if (X[m - 1] == Y[n - 1])
        memo[m][n] = 1 + lcsHelper(X, Y, m - 1, n - 1, memo);
    else
        memo[m][n] = max(lcsHelper(X, Y, m, n - 1, memo), lcsHelper(X, Y, m - 1, n, memo));

    return memo[m][n];
}

int lcs(const string &X, const string &Y) {
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    return lcsHelper(X, Y, m, n, memo);
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    cout << "Length of LCS is " << lcs(X, Y) << endl;

    return 0;
}