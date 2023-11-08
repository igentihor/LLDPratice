class Solution {
    
  public:
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid,
            int row0, int col0, vector<pair<int,int>>& vc) {
        int m = grid.size();
        int n = grid[0].size();
        vc.push_back({row-row0,col-col0});
        int delRow[] = {-1,1,0,0};
        int delCol[] = {0,0,-1,1};
        for(int i=0; i<4; i++) {
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol]==0
            && grid[nrow][ncol]==1) {
                visited[nrow][ncol]=1;
                dfs(nrow, ncol, visited, grid, row0, col0, vc);
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<int>> visited(m, vector<int>(n,0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    vector<pair<int,int>> vc;
                    visited[i][j]=1;
                    dfs(i, j, visited, grid, i, j, vc);
                    st.insert(vc);
                }
            }
        }
        return st.size();
    }
};
