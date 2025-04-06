vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<int> inDeg(V,0);
    vector<vector<int>> adj(V);
    for(auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        inDeg[v]++;
    }
    queue<int> q;
        for(int i=0;i<V;i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto& neighbour : adj[node]) {
                inDeg[neighbour]--;
                if(inDeg[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        return res;
}