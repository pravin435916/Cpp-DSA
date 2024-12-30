// 1. Time Complexity of the Pure Recursion (without memoization):
// In the pure recursive approach, each element in the triangle can branch into two possible paths: moving down or moving down-right. Therefore, the number of recursive calls grows exponentially.

// For each element triangle[row][col], there are two possible moves: one to the next row's current index (i) and one to the next row's adjacent index (i+1).
// The total number of recursive calls is approximately 2^n, where n is the number of rows in the triangle.
// Thus, time complexity of the pure recursion is:

// O(2^n), where n is the number of rows in the triangle.
class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& tri){
       if(i == tri.size()-1) return tri[i][j];
       int down = helper(i+1,j,tri);
       int downRight = helper(i+1,j+1,tri);
       return tri[i][j] + min(down,downRight);
    }
    int minimumTotal(vector<vector<int>>& tri) {
        return helper(0,0,tri);
    }
};