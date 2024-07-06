	//Function to find the level of node X.
class Solution
{
	public:
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    vector<bool> visited(V,false);
	    visited[0] =true;
	    queue<int> q;
	    q.push(0);
	    int level =0;
	    while(!q.empty()) {
	        int size = q.size();
	        while(size--) {
	        int cur = q.front();
	        q.pop();
	        if(cur == X) return level;  //and 
	        for(auto x : adj[cur]) {
	            if(!visited[x]) {
	                visited[x] = true;
	                q.push(x);
	            }
	        }
	        } //after traversing its all nodes on its level then increment level
	        level++;
	    }
	    return -1;
	}
};