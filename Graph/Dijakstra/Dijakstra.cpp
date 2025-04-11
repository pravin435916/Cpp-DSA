class Solution {
    public:
      typedef pair<int,int> P;
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
          vector<vector<P>> adj(V);
          for(auto& edge : edges) { // edges[i][0] = u, edges[i][1] = v, edges[i][2] = wt
              int u = edge[0];
              int v = edge[1];
              int wt = edge[2];
              adj[u].push_back({v,wt});
              adj[v].push_back({u,wt});
          }
          vector<int> dist(V,INT_MAX);
          priority_queue<P,vector<P>,greater<P>> pq;
          dist[src] = 0;
          pq.push({0,src}); // distance , node
          
          while(!pq.empty()) {
              auto p = pq.top();
              pq.pop();
              int node = p.second;
              int dis = p.first;
              for(auto& it : adj[node]) {
                  int neighbour = it.first;   // stored in adj list
                  int wt = it.second;
                  if(dis + wt < dist[neighbour]) { 
                      dist[neighbour] = dis + wt;  // update distance
                      pq.push({dist[neighbour],neighbour});  
                  }
              }
          }
          return dist;
      }
  };