#include<iostream>
using namespace std;
int uniquePaths(int i,int j) {
        // base case
        if(i == 0 && j == 0) return 1;
        if(j<0 || i<0) return 0;
        // do all stuff
        int left = uniquePaths(i,j-1);
        int up = uniquePaths(i-1,j);
        // sum of all ways
        return left+up;
    }
int main() {
    int m=3;
    int n=2;
    // approach go from end to start
    cout<<uniquePaths(m-1,n-1)<<endl;
}
// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down