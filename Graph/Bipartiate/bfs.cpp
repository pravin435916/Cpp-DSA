#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool bfs(int start,vector<int> &coloured,vector<int> adj[]) {
        queue<int> q;
	    q.push(start);
	    coloured[start]= 0;
	    while(!q.empty()) {
	      int node = q.front();
	      q.pop();
	      for(auto i : adj[node]) { 
	          if(coloured[i] == -1) {
	              coloured[i] = !coloured[node];  // mark with opposite colour
	              q.push(i);
	          }else if(coloured[i] == coloured[node]) {  // if already coloured and same as parent 
	                  return false;
	           }
	      }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> coloured(V,-1);  // initialize visited colour
	    for(int i=0;i<V;i++) {
	        if(coloured[i] == -1) {
	            if(bfs(i,coloured,adj) == false) return false;   // if bfs will give false then false
	        }
	    }
	    return true;
	}
};

int main() {
	int V = 5; // Number of vertices
	vector<int> adj[V]; // Adjacency list representation of the graph

	// Example edges (you can modify this to test different graphs)
	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(2);
	adj[3].push_back(4);
	adj[4].push_back(3);

	Solution s1;
	if (s1.isBipartite(V, adj)) {
		cout << "The graph is bipartite." << endl;
	} else {
		cout << "The graph is not bipartite." << endl;
	}

	return 0;
}