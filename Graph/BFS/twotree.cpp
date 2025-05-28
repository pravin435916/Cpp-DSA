class Solution {
public:
   int bfs(int node,unordered_map<int,vector<int>> &adj,int k,int N) {
    queue<pair<int,int>> q; //node , distance
    q.push({node,0});
    vector<bool> visited(N,false);
    visited[node] = true;
    int count = 0;
    while(!q.empty()) {
        int curNode = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(dist > k) continue; 
        count++;
        for(auto &neighbour : adj[curNode]) {
            if(!visited[neighbour]) {
               visited[neighbour] = true;
               q.push({neighbour,dist+1});
            }
        }
    }
    return count;
   }
    vector<int> findCount(vector<vector<int>>& edges,int k) {
        int N = edges.size() + 1;
        unordered_map<int,vector<int>> adj;
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> res(N);
        for(int i=0;i<N;i++) {
            res[i] = bfs(i,adj,k,N);
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int N = edges1.size() + 1;
        vector<int> result1 = findCount(edges1,k);
        vector<int> result2 = findCount(edges2,k-1);   // find k-1 count from edges 2
        int MaxTarget = *max_element(result2.begin(),result2.end());
        for(int i=0;i<result1.size();i++) {
            result1[i] += MaxTarget;
        }
        return result1;
    }
};