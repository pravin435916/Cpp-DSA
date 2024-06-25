#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;
class Graph {
private:
    unordered_map<int,list<int>> adjList;
public:
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v); // Since the graph is undirected
    }
    void removeEdge(int v, int w) {
        adjList[v].remove(w);
        adjList[w].remove(v);
    }
    void printGraph() {
        for (auto& pair : adjList) {
            cout << pair.first << " -> ";
            for (auto& x : pair.second) {
                cout << x << " ";
            }
            cout<<endl;
        }
    }
    void BFS(int start) {
        vector<bool> visited(adjList.size(),false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (auto x : adjList[node]) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        cout << endl;
    }
    void DFS(int start) {
        visited[start] = true;
        for (auto x : adjList[start]) {
            if (!visited[x]) {
                DFS(x);
            }
        }
    }
    // Get the adjacency list
    // std::unordered_map<int, std::list<int>> getAdjList() {
    //     return adjList;
    // }
};

int main() {
    Graph g;
    
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.printGraph();
    cout<<"bfs\n";
    g.BFS(0);
    cout<<"Dfs\n";
    g.DFS(0);


    return 0;
}
