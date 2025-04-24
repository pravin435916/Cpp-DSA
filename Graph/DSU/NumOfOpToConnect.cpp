class DSU {
    public:
        vector<int> parent, rank;
        // constructor
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        // find parent 
        int find(int i) {
            if (parent[i] != i)
                parent[i] = find(parent[i]);  // path compression
            return parent[i];
        }
    
        void unionByRank(int x, int y) {
            int px = find(x);
            int py = find(y);
    
            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[py] < rank[px]) {
                parent[py] = px;
            } else {
                parent[py] = px;
                rank[px]++;
            }
        }
    };
    
    
    class Solution {
    public:
        int makeConnected(int n, vector<vector<int>>& connections) {
            if (connections.size() < n - 1) return -1; // not enough cables
    
            DSU dsu(n);
            int components = n;
    
            for (auto& edge : connections) {
                int u = edge[0];
                int v = edge[1];
                if(dsu.find(u) != dsu.find(v)) {
                    dsu.unionByRank(u,v);
                    components--;
                }
            }
            return components-1;  // need n-1 edges to connect n vertices
            // ex. 0 1 2 3 4 5 
            // 0-1 0-2 0-3   ek hi component me 
            // 1-2,1-3 already same parent 
        }
    };