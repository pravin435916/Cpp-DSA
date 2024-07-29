#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void floydWarshall(vector<vector<int>> &dist) {
    int n = dist.size();
    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n = 4; // Number of vertices
    int m = 6; // Number of edges

    // Adjacency list representation of the graph
    vector<vector<pair<int, int>>> adjList(n);

    // List of edges in the format (u, v, weight)
    vector<vector<int>> edges = {
        {0, 1, 3},
        {0, 3, 5},
        {1, 0, 2},
        {1, 3, 4},
        {2, 1, 1},
        {3, 2, 2}
    };

    // Populate the adjacency list
    for (int i = 0; i < m; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        // adjList[u].emplace_back(v, weight);
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});

    }

    // Initialize the distance matrix with INF and 0 for the diagonal
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    // Fill the distance matrix using the adjacency list
    for (int u = 0; u < n; ++u) {
        for (const auto &neighbor : adjList[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            dist[u][v] = weight;
        }
    }

    floydWarshall(dist);

    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}