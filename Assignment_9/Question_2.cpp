#include <iostream>
#include <vector>

using namespace std;

void DFSUtil(int u, const vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFSUtil(v, adj, visited);
        }
    }
}

void DFS(int start, const vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<bool> visited(V, false);
    cout << "DFS traversal starting from vertex " << start << ": ";
    DFSUtil(start, adj, visited);
    cout << endl;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> adj(V);

    cout << "Enter " << E << " edges (u v) with 0-based indexing:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Comment if directed graph
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    DFS(start, adj);

    return 0;
}