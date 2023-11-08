class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> dist(N, INT_MAX);
        queue<pair<int,int>> q;
        q.push({src,0});
        dist[src] = 0;
        while(!q.empty()) {
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();
            for(auto it : adj[node]) {
                if(dist[it] == INT_MAX) {
                    dist[it] = distance+1;
                    q.push({it,dist[it]});
                } else {
                    dist[it] = min(dist[it], distance+1);
                }
            }
        }
        for(int i=0; i<N; i++) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        return dist;
    }
};
