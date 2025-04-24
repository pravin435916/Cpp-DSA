class Solution {
    public:
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
          vector<int> result(V,1e8);
          result[src] = 0;
          // relax edges V-1 times
          for(int count=1;count<=V-1;count++) {
              for(auto& edge : edges) {
                  int u  = edge[0];
                  int v = edge[1];
                  int wt = edge[2];
                  if(result[u] != 1e8 && result[u] + wt < result[v]) {
                      result[v] = result[u] + wt;
                  }
              }
          }
          // if after V-1 edges if still relaxing and updating weights then negative cycle
          // so lets check one more time 
          for(auto& edge : edges) {
                  int u  = edge[0];
                  int v = edge[1];
                  int wt = edge[2];
                  if(result[u] != 1e8 && result[u] + wt < result[v]) {
                      return {-1};
                  }
          }
          return result;
          
      }
  };