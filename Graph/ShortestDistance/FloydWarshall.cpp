class Solution {
    public:
      void floydWarshall(vector<vector<int>> &dist) {
          int n = dist.size();
          const int INF = 1e8;
          for(int k=0;k<n;k++) { // pass throgh each vertices
              // now simple grid traverse
              for(int i=0;i<n;i++) {
                  for(int j=0;j<n;j++) { // for 3,2    go 3 to k then k to 3 
                      if(dist[i][k] < INF && dist[k][j] < INF)
                      dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                  }
              }
          }
      }
  };