#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void dijkstra(int start, const vector<vector<pair<int, int>>> &graph, vector<int> &dist) {
    int n = graph.size();
    dist.assign(n, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d != dist[u]) continue;

        for (const auto &edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].emplace_back(v, weight);
        graph[v].emplace_back(u, weight); // Comment this line if the graph is directed
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    vector<int> dist;
    dijkstra(start, graph, dist);

    cout << "Shortest distances from vertex " << start << " are:" << endl;
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
