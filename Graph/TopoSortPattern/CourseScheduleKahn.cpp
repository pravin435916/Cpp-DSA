
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.
class Solution {
public:
   // Using Kahn's Algorithm
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        queue<int> q;
        vector<int> inDeg(V, 0);
        vector<int> ans;
        //calculate indegree
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);  //bcoz its directed
            inDeg[edges[i][1]]++;
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
                inDeg[adj[node][i]]--;
                if(inDeg[adj[node][i]] == 0) {
                    q.push(adj[node][i]);
                }
            }
        }
        //check ans size and no. of courses size
        if(ans.size() != V) return false;
        else return true;
        
    }
};