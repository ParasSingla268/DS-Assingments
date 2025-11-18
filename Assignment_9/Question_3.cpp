#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge
{
    int u, v, w;
};

int findSet(int u, vector<int> &parent)
{
    if (parent[u] == u)
        return u;
    return parent[u] = findSet(parent[u], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findSet(u, parent);
    v = findSet(v, parent);
    if (u != v)
    {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[v] < rank[u])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
}

void Kruskal(int V, vector<Edge> &edges)
{
    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b)
         { return a.w < b.w; });

    vector<Edge> MST;
    int mstWeight = 0;

    for (auto &e : edges)
    {
        if (findSet(e.u, parent) != findSet(e.v, parent))
        {
            MST.push_back(e);
            mstWeight += e.w;
            unionSet(e.u, e.v, parent, rank);
        }
    }

    cout << "Edges in MST using Kruskal's Algorithm:\n";
    for (auto &e : MST)
    {
        cout << e.u << " -- " << e.v << " : " << e.w << "\n";
    }
    cout << "Total weight: " << mstWeight << "\n";
}

void Prim(int V, vector<vector<pair<int, int>>> &adj)
{
    vector<int> key(V, 1e9);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    key[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u])
            continue;
        inMST[u] = true;

        for (auto &nbr : adj[u])
        {
            int v = nbr.first;
            int w = nbr.second;
            if (!inMST[v] && w < key[v])
            {
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST using Prim's Algorithm:\n";
    int totalWeight = 0;
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " -- " << i << " : " << key[i] << "\n";
        totalWeight += key[i];
    }
    cout << "Total weight: " << totalWeight << "\n";
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;
    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges (u v w) with 0-based indexing:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    cout << "Choose MST Algorithm:\n1. Kruskal\n2. Prim\nEnter choice: ";
    int choice;
    cin >> choice;

    if (choice == 1)
        Kruskal(V, edges);
    else if (choice == 2)
        Prim(V, adj);
    else
        cout << "Invalid choice.\n";

    return 0;
}