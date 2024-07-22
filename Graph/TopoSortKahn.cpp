#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;
class TopoSortKahn{	
    public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        queue<int> q;
        vector<int> inDeg(V, 0);
        vector<int> ans;
        //calculate indegree
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                inDeg[v]++;
            }
        }
        //push 0 indegree 
        for(int i=0;i<inDeg.size();i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }
        //traverse neighbour nodes
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++) {
                int neighbour = adj[node][i];
                inDeg[neighbour]--;
                if(inDeg[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        return ans;
	}
};
int main() {
    int V = 4;
    vector<int> adj[V] ={{1,2},{1,3},{3,2},{2,4}}

    TopoSortKahn topo;
    vector<int> result = topo.topoSort(V, adj);

    if (!result.empty()) {
        cout << "Topological Sort of the given graph: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout <<endl;
    }

    return 0;
}
