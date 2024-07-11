class Solution{	
    public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        queue<int> q;
        vector<int> inDeg(V, 0);
        vector<int> ans;
        //calculate indegree
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                inDeg[v]++;
            }
        }
        //push 0 indegree 
        for(int i=0;i<inDeg.size();i++) {
            if(inDeg[i] == 0) {
                q.push(i);
            }
        }
        //traverse neighbour nodes
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++) {
                int neighbour = adj[node][i];
                inDeg[neighbour]--;
                if(inDeg[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        return ans;
	}
};