class Solution {
public:
    bool bfs(int start,vector<int> &coloured,vector<int> adj[]) {
        queue<int> q;
	    q.push(start);
	    coloured[start]= 0;
	    while(!q.empty()) {
	      int node = q.front();
	      q.pop();
	      for(auto i : adj[node]) { 
	          if(coloured[i] == -1) {
	              coloured[i] = !coloured[node];  // mark with opposite colour
	              q.push(i);
	          }else if(coloured[i] == coloured[node]) {  // if already coloured and same as parent 
	                  return false;
	           }
	      }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> coloured(V,-1);  // initialize visited colour
	    for(int i=0;i<V;i++) {
	        if(coloured[i] == -1) {
	            if(bfs(i,coloured,adj) == false) return false;   // if bfs will give false then false
	        }
	    }
	    return true;
	}
};