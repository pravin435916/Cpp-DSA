class Solution {
    public:
      
      bool isCycle(int V, vector<vector<int>>& edges) {
          vector<int> parent(V,-1);
          for(auto &edge : edges) {
              int u = edge[0];
              int v = edge[1];
              int pu = find(u,parent);
              int pv = find(v,parent);
              
              if(pu == pv) return true;
              
              parent[pu] = pv;   //joins
          }
          return false;
      }
      
      private:
      int find(int i,vector<int> &parent) {
          if(parent[i] == -1) return i;
          return parent[i] =find(parent[i],parent);
      }
  };