#include <vector>
#include <queue>
using namespace std;

// Function to check if the position is valid
bool isValid(int x, int y, int N, vector<vector<int>>& A) {
    return (x > 0 && x <= N && y > 0 && y <= N && A[x][y] == 0);
}

int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
    // Create an (N+1)x(N+1) board to handle 1-based indexing
    vector<vector<int>> A(N+1, vector<int>(N+1, 0));
    queue<pair<int, int>> q;

    // Correct possible moves for a knight
    vector<int> rows = {-2,-2, 2, 2, 1,-1,1, -1};
    vector<int> cols = {1, -1, 1, -1,-2, -2, 2, 2};

    // If the knight is already at the target position
    if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]) return 0;

    // Start BFS from the initial position of the knight
    q.push({KnightPos[0], KnightPos[1]});
    A[KnightPos[0]][KnightPos[1]] = 1; // Mark as visited
    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            pair<int, int> current = q.front();
            int curX = current.first;  // row
            int curY = current.second; // col
            q.pop();

            // If we reach the target position
            if (curX == TargetPos[0] && curY == TargetPos[1]) return steps;

            // Explore all 8 possible moves of the knight
            for (int j = 0; j < 8; ++j) {
                int newX = curX + rows[j];  // new row
                int newY = curY + cols[j];  // new col

                if (isValid(newX, newY, N, A)) {
                    q.push({newX, newY});
                    A[newX][newY] = 1; // Mark as visited
                }
            }
        }
        ++steps;
    }

    return -1; // If no path is found
}
