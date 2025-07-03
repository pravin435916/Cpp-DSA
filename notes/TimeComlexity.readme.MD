# 📘 C++ Time Complexity Cheatsheet & Notes

This document serves as your go-to reference for understanding time complexity in C++. It includes how to estimate time complexity, optimize code, and choose efficient data structures.

---

## ✅ 1. What is Time Complexity?

Time Complexity measures how the runtime of an algorithm grows with the input size `n`. It is expressed using Big-O notation.

| Big-O        | Name              | Example                           |
|--------------|-------------------|-----------------------------------|
| O(1)         | Constant           | Accessing array element           |
| O(log N)     | Logarithmic        | Binary search                     |
| O(N)         | Linear             | Single loop                       |
| O(N log N)   | Log-linear         | Merge Sort, Quick Sort (avg case) |
| O(N²)        | Quadratic          | Nested loops                      |
| O(N³)        | Cubic              | Triple nested loops               |
| O(2^N)       | Exponential        | Recursion, Backtracking           |
| O(N!)        | Factorial          | Permutations, TSP                 |

---

## ✅ 2. STL Operation Time Complexities

| Operation                         | Time Complexity     |
|----------------------------------|---------------------|
| `vector.push_back()`             | Amortized O(1)      |
| `map` / `set` insert/find        | O(log N)            |
| `unordered_map` insert/find      | O(1) avg, O(N) worst|
| `sort()`                         | O(N log N)          |
| `binary_search()`                | O(log N)            |
| `string.substr()` / `append()`   | O(N)                |
| `priority_queue.push()`          | O(log N)            |

---

## ✅ 3. Time Limit vs Input Size Cheatsheet

> 🧠 **Rule of Thumb**: 1 second = up to **10⁸ operations**

| Input Size N    | Acceptable Complexity       |
|------------------|-----------------------------|
| ≤ 10             | O(N!), O(2ⁿ)                |
| ≤ 20             | O(2ⁿ × N)                   |
| ≤ 100            | O(N³)                       |
| ≤ 1,000          | O(N²)                       |
| ≤ 10,000         | O(N√N), O(N log N)          |
| ≤ 100,000        | O(N log N)                  |
| ≤ 1,000,000      | O(N)                        |
| > 10⁶            | O(1), O(log N)              |

---

## ✅ 4. Estimating Time Complexity from Constraints

### 🔍 Steps:

1. **Read constraints carefully**
2. Match input size `N` with the table above
3. Choose data structures and approaches accordingly
4. Avoid brute force if `N > 1e4` and your logic is O(N²)

---

## ✅ 5. Time Complexities by Problem Type

| Problem Type         | Expected Complexity |
|----------------------|---------------------|
| Searching sorted     | O(log N)            |
| Sorting              | O(N log N)          |
| Subarray problems    | O(N²) or optimized O(N) |
| DP (1D, 2D)          | O(N), O(N²)         |
| Graph BFS / DFS      | O(V + E)            |
| Dijkstra / A*        | O((V + E) log V)    |
| Segment Tree         | O(log N) per op     |
| Backtracking         | O(2ⁿ), O(N!)        |

---

## ✅ 6. TLE Detection & Optimization Tips

### ❌ Brute Force Example:
```cpp
for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++)
    sum++;
// O(N²) → Not acceptable if N > 10⁴
