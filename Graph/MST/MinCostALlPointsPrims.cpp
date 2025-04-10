// Appraoch MST using Prims Algo according to min weight choose path sum
        // first we have to make adj to store all dis
        // then apply prims algo same copy paste
        int V = points.size();
        vector<vector<P>> adj(V);
        for(int i=0;i<V;i++) {
            for(int j=i+1;j<V;j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int distance = abs(x2-x1) + abs(y2-y1);
                
                adj[i].push_back({j,distance});
                adj[j].push_back({i,distance});
                
            }
        }
        
        return primsAlgo(adj,V);