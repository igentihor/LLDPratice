#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(int V, vector<int> adj[]) {
    vector<int> ans;
    bool visited[V] = {false};
    for(int j=0; j<V; j++) {
        if(false == visited[j]) {
            queue<int> q;
            q.push(j);
            visited[j] = true;
            while(!q.empty()) {
                int front = q.front();
                q.pop();
                ans.push_back(front);
                for(auto i : adj[front]) {
                    if(visited[i] == false) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
    return ans;
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
    vector<int> ans = bfs(V, adj_list);
    for(auto i : ans) {
        cout << i << " ";
    }
}
