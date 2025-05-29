/*
Approach:
1. The problem involves two trees (represented by edges1 and edges2) and an integer k.
2. For each node in the first tree (edges1), we want to count how many nodes are within distance k using BFS.
3. For the second tree (edges2), for each node, count how many nodes are within distance k-1.
4. Find the maximum count from the second tree's results.
5. For each node in the first tree, add this maximum value to its count.
6. Return the resulting vector.

Step-by-step:
- Build adjacency lists for both trees.
- For each node in both trees, use BFS to count nodes within the required distance.
- For the second tree, keep track of the maximum count.
- Add this maximum to each node's count from the first tree.
- Return the final result.
*/

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