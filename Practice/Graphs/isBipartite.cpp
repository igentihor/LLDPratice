bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    for(int i=0; i<V; i++) color[i]=-1;
	    for(int i=0; i<V; i++) {
	        if(color[i] == -1) {
	            queue<int> q;
	            color[i] = 0;
	            q.push(i);
	            while(!q.empty()) {
	                int front = q.front();
	                q.pop();
	                for(auto j : adj[front]) {
	                    if(color[j] != -1 && color[j] == color[front]) {
	                        return false;
	                    }
	                    if(color[j] == -1) {
	                        color[j] = (color[front]==0) ? 1 : 0;
	                        q.push(j);
	                    }
	                }
	            }
	        }
	    }
	    return true;
	}
