// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// No of connected component
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] == 1 && !visited[i] ) {
                dfs(i, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ct = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ct++;
                dfs(i, isConnected, visited);
            }
        }
        return ct;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        vector<vector<int>> connected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
        int res = obj.findCircleNum(connected);

        cout<<res<<endl;
    }
}