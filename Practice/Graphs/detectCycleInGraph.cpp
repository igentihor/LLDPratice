#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<int> adj[]) {
        int visited[V] = {0};
        for(int i=0; i<V; i++) {
            if(visited[i]==0) {
                queue<pair<int,int>> q;
                q.push({i,-1});
                visited[i]=1;
                while(!q.empty()) {
                    pair<int,int> front = q.front();
                    q.pop();
                    for(auto j : adj[front.first]) {
                        if(j!=front.second && visited[j]==1) {
                            return true;
                        }
                        if(visited[j]==0) {
                            q.push({j,front.first});
                            visited[j]=1;
                        }
                    }
                }
            }
        }
        return false;
    }

int main() {
	int V,E;
    cout << "Enter number of vertices\n" << endl;
    cin >> V;
    cout << "Enter number of edges\n" << endl;
    cin >> E;
    cout << "Enter edges\n" << endl;

    int adj_matrix[V][V] = {0};     //adjacency matrix
    vector<int> adj_list[V];    //adjacency list
    for(int i=0; i<E; i++) {
        int x,y;
        cin >> x >> y;

        /*storing in adjacency matrix*/
        adj_matrix[x][y] = 1;
        adj_matrix[y][x] = 1;

        /*storing in adjacency list*/
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
	cout << isCycle(V, adj_list) << endl;	
}

