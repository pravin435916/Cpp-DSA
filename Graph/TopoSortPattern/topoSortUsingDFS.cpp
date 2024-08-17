#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(vector<int> adj[], vector<bool> &visited, int node, stack<int> &st)
    {
        visited[node] = true;
        // Traverse neighbors
        for (int i : adj[node])
        {
            if (!visited[i])
            {
                dfs(adj, visited, i, st);
            }
        }
        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, i, st);
            }
        }
        vector<int> res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
