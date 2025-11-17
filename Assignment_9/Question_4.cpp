#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

void Dijkstra(int src, int V, const vector<vector<pair<int, int>>> &adj)
{
    vector<int> dist(V, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        if (currDist > dist[u])
            continue;

        for (auto &nbr : adj[u])
        {
            int v = nbr.first;
            int w = nbr.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << ": ";
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];
        cout << "\n";
    }
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges (u v w), 0-based indexing:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph; remove if directed
    }

    int src;
    cout << "Enter source vertex for Dijkstra's algorithm: ";
    cin >> src;

    Dijkstra(src, V, adj);
    return 0;
}