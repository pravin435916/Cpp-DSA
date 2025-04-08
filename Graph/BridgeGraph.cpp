class Solution {
    public:
      void dfs(int node, vector<vector<int>>& adj,int c,int d,vector<int> &vis) {
          vis[node] = 1;
          for(auto it : adj[node]) {
              if(!vis[it] && !(node == c && it == d)) {
                  dfs(it,adj,c,d,vis);
              }
          }
      }
      bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
          // Code here
          vector<vector<int>> adj(V);
          vector<int> vis(V,0);
          for(auto &edge: edges) {
              int u = edge[0];
              int v = edge[1];
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
          dfs(c,adj,c,d,vis);
          if(vis[d]) return false;
          return true;
      }
  };