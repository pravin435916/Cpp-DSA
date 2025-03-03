# Longest Common Subsequence (LCS)

## Introduction
The **Longest Common Subsequence (LCS)** problem is a classic dynamic programming problem that finds the longest subsequence present in both given strings while maintaining their relative order.

## Approaches
We will discuss three approaches to solve the **LCS** problem:
1. **Recursive Approach** (Brute Force)
2. **Top-Down Dynamic Programming (Memoization)**
3. **Bottom-Up Dynamic Programming (Tabulation)**

## 1. Recursive Approach
### Steps:
1. If either string is empty, return `0`.
2. If `s1[i] == s2[j]`, add `1` and recurse for `i+1, j+1`.
3. Otherwise, take the maximum of two cases:
   - Skipping a character in `s1`
   - Skipping a character in `s2`

### Code:
```cpp
int lcs_recursive(int i, int j, string &s1, string &s2) {
    if (i >= s1.length() || j >= s2.length()) return 0;
    if (s1[i] == s2[j]) {
        return 1 + lcs_recursive(i + 1, j + 1, s1, s2);
    }
    return max(lcs_recursive(i + 1, j, s1, s2), lcs_recursive(i, j + 1, s1, s2));
}
```
### Complexity:
- **Time Complexity:** `O(2^n)`, since we explore all possibilities.
- **Space Complexity:** `O(n + m)` (recursive stack).

---

## 2. Top-Down Dynamic Programming (Memoization)
### Steps:
1. Use a `dp` table to store already computed results.
2. If `s1[i] == s2[j]`, store `1 + dp[i+1][j+1]`.
3. Otherwise, store `max(dp[i+1][j], dp[i][j+1])`.

### Code:
```cpp
int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if (i >= s1.length() || j >= s2.length()) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i] == s2[j]) {
        return dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2, dp);
    }
    return dp[i][j] = max(solve(i + 1, j, s1, s2, dp), solve(i, j + 1, s1, s2, dp));
}

int lcs_top_down(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(0, 0, s1, s2, dp);
}
```
### Complexity:
- **Time Complexity:** `O(n * m)`, since each state is computed once.
- **Space Complexity:** `O(n * m) + O(n + m)` (dp table + recursion stack).

---

## 3. Bottom-Up Dynamic Programming (Tabulation)
### Steps:
1. Use a `dp` table where `dp[i][j]` stores the LCS of `s1[0..i-1]` and `s2[0..j-1]`.
2. If `s1[i-1] == s2[j-1]`, take `1 + dp[i-1][j-1]`.
3. Otherwise, take `max(dp[i-1][j], dp[i][j-1])`.
4. Return `dp[n][m]`.

### Code:
```cpp
int longestCommonSubsequence(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
```
### Complexity:
- **Time Complexity:** `O(n * m)`, iterating over the DP table.
- **Space Complexity:** `O(n * m)`, storing results.
- **Optimized Space Complexity:** `O(min(n, m))` using rolling arrays.

---

## Example
### **Input:**
```cpp
s1 = "abcde";
s2 = "ace";
```
### **Output:**
```
Length of LCS: 3
```
### **Explanation:**
The LCS is "ace" with a length of `3`.

## Alternative Space Optimization
By storing only the last two rows of the DP table, space complexity can be reduced to `O(m)`.

---
## Usage
- **Biology:** DNA sequence alignment.
- **Text Comparison:** File diff tools (e.g., Git diff).
- **Data Compression:** Identifying common patterns in data.

## Conclusion
The **LCS problem** can be solved using three approaches:
1. **Recursive Approach** (Brute Force) - Exponential time complexity.
2. **Top-Down Memoization** - Reduces redundant calculations.
3. **Bottom-Up DP (Tabulation)** - Efficient and preferred for larger inputs.

---
### ⭐ If you found this useful, consider ⭐ the repository!

