  bool helper(string &pattern, string &str, int i, int j, vector<vector<int>> &dp) {
    // Base Case: If both pattern and str are fully matched
    if (i == pattern.size() && j == str.size()) return true;
    // If pattern is exhausted but str is not, or vice versa
    if (i == pattern.size() || j == str.size()) {
        if (i < pattern.size() && pattern[i] == '*') {
            // Skip all '*' at the end of the pattern
            return helper(pattern, str, i + 1, j, dp);
        }
        return false;
    }

    // Check if result is already computed
    if (dp[i][j] != -1) return dp[i][j];

    // Match '?' or exact characters
    if (pattern[i] == str[j] || pattern[i] == '?') {
        return dp[i][j] = helper(pattern, str, i + 1, j + 1, dp);
    }

    // Handle '*' wildcard
    if (pattern[i] == '*') {
        return dp[i][j] = helper(pattern, str, i + 1, j, dp) || 
                          helper(pattern, str, i, j + 1, dp) || 
                          helper(pattern, str, i + 1, j + 1, dp);
    }

    // Characters don't match
    return dp[i][j] = false;
}

int wildCard(string pattern, string str) {
    vector<vector<int>> dp(pattern.size(), vector<int>(str.size(), -1));
    return helper(pattern, str, 0, 0, dp) ? 1 : 0;
}