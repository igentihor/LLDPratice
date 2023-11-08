class Solution {
    
  private:
    bool dfs(int node, int visited[], int pathVisited[], vector<int> adj[], int safeNode[]) {
        visited[node] = 1;
        pathVisited[node] = 1;
        for(auto adjNode : adj[node]) {
            if(pathVisited[adjNode] == 1) {
                return true;
            } else if(!visited[adjNode]) {
                if(dfs(adjNode, visited, pathVisited, adj, safeNode)==true) {
                    return true;
                }
            }
        }
        safeNode[node]=1;
        pathVisited[node]=0;
        return false;
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        int visited[V] = {0};
        int pathVisited[V] = {0};
        int safeNode[V] = {0};
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                dfs(i, visited, pathVisited, adj, safeNode);
            }
        }
        vector<int> ans;
        for(int i=0; i<V; i++) {
            if(safeNode[i]==1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
