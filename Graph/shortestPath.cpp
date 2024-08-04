#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    const vector<int> directions = {0, 1, 0, -1, 0};
    // Function to check if a cell is within the grid and is 1
    bool isValid(int x, int y, int N, int M, vector<vector<int>> &A){
        return x >= 0 && y >= 0 && x < N && y < M && A[x][y] == 1;
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y){
        if (A[0][0] == 0 || A[X][Y] == 0)
            return -1; // If start or end is blocked

        queue<pair<int, int>> q;
        q.push({0, 0});
        A[0][0] = 0; // Mark as visited
        int steps = 0;

        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; ++i){
                pair<int, int> current = q.front();
                int curX = current.first;
                int curY = current.second;
                q.pop();

                if (curX == X && curY == Y)
                    return steps; // reached

                for (int j = 0; j < 4; ++j) {
                    int newX = curX + directions[j];
                    int newY = curY + directions[j + 1];

                    if (isValid(newX, newY, N, M, A)) {
                        q.push({newX, newY});
                        A[newX][newY] = 0; // Mark as visited
                    }
                }
            }
            ++steps;
        }

        return -1; // If no path found
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}