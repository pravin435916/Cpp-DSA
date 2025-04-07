bool isCyclic(int V, vector<vector<int>> &edges) {
    // code here
    vector<int> inDeg(V,0);
    vector<vector<int>> adj(V);
    for(auto& edge : edges) {
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
    int count = 0;
    while(!q.empty()) {
        int node =q.front();
        q.pop();
        count++;
        for(auto& neighbour : adj[node]) {
            inDeg[neighbour]--;
            if(inDeg[neighbour] == 0) {
                q.push(neighbour);
            }
        }
            
    }
    return count != V; // topo sort is not possible for all means cycle is present
}