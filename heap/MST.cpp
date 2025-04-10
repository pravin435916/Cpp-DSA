public:
  typedef pair<int,int> P;
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> parent(V,-1);
        vector<bool> visited(V,false);
        priority_queue<P,vector<P>,greater<P>> minHeap;
        // {wt,node}
        minHeap.push({0,0});
        int sum = 0;
        while(!minHeap.empty()) {
            auto p = minHeap.top();
            minHeap.pop();
            int wt = p.first;
            int node = p.second;
            
            if(visited[node]) continue;
            visited[node] = true;
            sum += wt;
            for(auto &tmp : adj[node]) {
                int neighbour = tmp[0];
                int neighbour_wt = tmp[1];
                
                if(!visited[neighbour]) {
                    minHeap.push({neighbour_wt,neighbour});
                }
            }
            
        }
        return sum;
    }