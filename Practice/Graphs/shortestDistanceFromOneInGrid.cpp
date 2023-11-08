vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size();
	    int n = grid[0].size();
	    int delRow[] = {-1,1,0,0};
	    int delCol[] = {0,0,-1,1};
	    vector<vector<int>> nearestCell(m, vector<int>(n,0));
	    vector<vector<int>> visited(m, vector<int>(n,0));
	    queue<pair<pair<int,int>,int>> q;
	    for(int i=0; i<m; i++) {
	        for(int j=0; j<n; j++) {
	            if(grid[i][j] == 1) {
	                q.push({{i,j},0});
	                visited[i][j] = 1;
	                nearestCell[i][j] = 0;
	            }
	        }
	    }
	    while(!q.empty()) {
	        int xx = q.front().first.first;
	        int yy = q.front().first.second;
	        int dis = q.front().second;
	        q.pop();
	        for(int j=0; j<4; j++) {
	            if(xx+delRow[j] >=0 && xx+delRow[j] < m && yy+delCol[j] >= 0 && yy+delCol[j] < n && visited[xx+delRow[j]][yy+delCol[j]] == 0) {
	                q.push({{xx+delRow[j],yy+delCol[j]},dis+1});
	                visited[xx+delRow[j]][yy+delCol[j]] = 1;
	                nearestCell[xx+delRow[j]][yy+delCol[j]] = dis+1;
	            }
	        }
	    }
	    return nearestCell;
	}
