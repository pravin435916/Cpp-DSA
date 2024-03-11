#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printPath(int sr, int sc, int er, int ec, string s, vector<vector<bool>>& visited) {
    if (sr > er || sc > ec || visited[sr][sc]) return;
    if (sr == er && sc == ec) {
        cout << s << endl;
        return;
    }
    
    visited[sr][sc] = true; // Marking the visited Nhi to chuha pagl ho jayega
    
    // move right
    printPath(sr, sc + 1, er, ec, s + "R", visited);
    // move down
    printPath(sr + 1, sc, er, ec, s + "D", visited);
    
    visited[sr][sc] = false; // Backtracking: marking the current cell as not visited
}

int main() {
    int row = 3;
    int col = 3;
    
    // Creating a 2D boolean array to track visited cells
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    
    printPath(0, 0, row - 1, col - 1, "", visited);
    return 0;
}
