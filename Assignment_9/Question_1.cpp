#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int start, const vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS traversal starting from vertex " << start << ": ";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
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
        adj[v].push_back(u); // Comment this line if graph is directed
    }

    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    BFS(start, adj);

    return 0;
}