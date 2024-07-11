#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i=0;i<M;i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
       vector<int> dest(N,-1);
       vector<bool> visited(N,false);
       queue<int> q;
       q.push(src);
       dest[src] = 0;   //src to src ditance is 0
       visited[src] = true;  //marked src to visited
       while(!q.empty()) {
           int node = q.front();
           q.pop();
           
           for(int j=0;j<adj[node].size();j++) {
               if(!visited[adj[node][j]]) {
                   visited[adj[node][j]] = true;
                   dest[adj[node][j]] = dest[node]+1;  //main step destance me daldo uske parent ka distance +1
                   q.push(adj[node][j]);
               }
           }
        //     for(auto i : adj[node]) {
        //        if(!visited[i]) {
        //            visited[i] = true;
        //            dest[i] = dest[node]+1;  //main step destance me
        //            q.push(i);
        //        }
        //    }
       }
       return dest;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; 
                cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; 
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}