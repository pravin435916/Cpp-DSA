# 🟢 Easy Problems (Fundamental Recursion)
These problems introduce backtracking and decision-based recursion.

## 1️⃣ Generate All Subsequences of a String
Problem: Given a string, generate all possible subsequences.
Example:
Input: "abc"
Output: ["", "a", "b", "c", "ab", "ac", "bc", "abc"]
Similar to your question, but focus on understanding include/exclude decisions.

## 2️⃣ Generate All Subsets of an Array
Problem: Given an array, print all subsets (power set).
Example:
Input: [1, 2]
Output: [[], [1], [2], [1,2]]
Decision Points:
Include or exclude each element.

## 3️⃣ Print All Binary Strings of Length N
Problem: Generate all possible binary strings of length N.
Example:
Input: N = 3
Output: ["000", "001", "010", "011", "100", "101", "110", "111"]
Decision Points:
At each step, choose 0 or 1.
🟡 Medium Problems (Backtracking & Constraints Handling)
4️⃣ Generate All Balanced Parentheses
Problem: Given N, generate all valid balanced parentheses strings.
Example:
Input: N = 3
Output: ["((()))", "(()())", "(())()", "()(())", "()()()"]
Decision Points:
At any position, we can place ( if count of ( is < N.
We can place ) if count of ) is < count of (.
## 5️⃣ Word Break (Recursive)
Problem: Given a dictionary of words and a string, determine if it can be segmented into valid words.
Example:
Input: "applepenapple", Dict = ["apple", "pen"]
Output: True ("apple pen apple")
Decision Points:
Try to split the string at each index and check if the left part is in the dictionary.
## 6️⃣ Generate All Unique Permutations of an Array
Problem: Given an array, print all unique permutations.
Example:
Input: [1, 2, 3]
Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
Decision Points:
Swap elements and recurse.
🔴 Hard Problems (Backtracking & Optimization)
## 7️⃣ N-Queens Problem
Problem: Place N queens on an N x N chessboard so that no two queens attack each other.
Example:

Input: N = 4
Output: [[2 4 1 3], [3 1 4 2]]
Decision Points:
Choose a row for each column.
Backtrack if a queen is under attack.
## 8️⃣ Sudoku Solver
Problem: Solve a 9x9 Sudoku puzzle using backtracking.
Decision Points:
Place a number from 1-9 in an empty cell.
Backtrack if the placement is invalid.
## 9️⃣ Combination Sum
Problem: Given an array arr and a target sum K, print all unique subsets where the sum equals K.
Example:

Input: arr = [2, 3, 6, 7], target = 7
Output: [[2, 2, 3], [7]]
Decision Points:
Include or exclude the current number.
If included, call recursion with target - arr[i].
🔟 Rat in a Maze
Problem: Find a path from (0,0) to (N-1, N-1) in a matrix of 0s (blocked) and 1s (allowed).
Example:

Input:
[
  [1, 0, 0, 0],
  [1, 1, 0, 1],
  [0, 1, 0, 0],
  [1, 1, 1, 1]
]
Output: "DDRDRR"
Decision Points:
Move Down, Right, Left, Up if possible.
🔹 Summary Table
Problem	Type	Decision Making
Generate Subsequences	Easy	Include/Exclude
Generate Subsets of Array	Easy	Include/Exclude
Print All Binary Strings	Easy	Choose 0 or 1
Balanced Parentheses	Medium	Add ( or )
Word Break	Medium	Split at each index
Unique Permutations	Medium	Swap & Recursion
N-Queens	Hard	Choose row for each column
Sudoku Solver	Hard	Try numbers 1-9
Combination Sum	Hard	Include/Exclude elements
Rat in a Maze	Hard	Move Down, Right, Left, Up
🚀 How to Master These Problems?
Start with easy problems (subsequences, binary strings, subsets).
Move to medium problems (N-Queens, Word Break, Permutations).
Solve hard problems using pruning & constraints (Sudoku, Maze, Combination Sum).
Analyze recursion trees to understand decision paths.
Write & debug recursively, then optimize using DP when necessary.