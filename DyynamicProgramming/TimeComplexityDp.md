### 1D Recursion & DP:

#### Basic Recursion:
- Time Complexity: `O(2^n)`
  // Example: Fibonacci, Staircase Problem without DP

#### 1D DP (Top-Down or Bottom-Up):
- Time Complexity: `O(n)`
  // Reason: Each state is computed once and reused.
  // Example: Fibonacci using Memoization or Tabulation.

---

### 2D Recursion & DP:

#### Basic 2D Recursion:
- Time Complexity: `O(2^n * 2^m)` (for a grid of size `n*m`)
  // Example: Unique Paths without DP, Matrix Path Problems

#### 2D DP (Top-Down or Bottom-Up):
- Time Complexity: `O(n * m)`
  // Reason: Each cell/state in the 2D matrix is computed once and reused.
  // Example: Unique Paths with DP, Longest Common Subsequence, Knapsack with DP

---

### Common Patterns in DP:

#### 1D Space Optimization:
- Some 1D/2D DP problems can be reduced to `O(1)` or `O(n)` space by optimizing the recursion and using fewer variables.
  // Example: Fibonacci with constant space: `O(1)`

#### 2D to 1D Space Optimization:
- Many 2D DP problems can be optimized to use `O(n)` space by only keeping track of the current and previous row.
  // Example: Longest Common Subsequence space optimization from `O(n*m)` to `O(n)`

---

### Special DP Variations:

#### Knapsack (0/1) Recursion:
- Time Complexity: `O(2^n)`
  // Reason: For each item, either you take it or leave it (binary choices).

#### Knapsack DP:
- Time Complexity: `O(n * W)`
  // n = number of items, W = maximum weight

---

### DP with State Variables:
- Time Complexity: Depends on the number of states and transitions between them.
  // Example: DP on trees, Graph DP, String Matching DP
