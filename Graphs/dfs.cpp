#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g; // adjacency matrix
vector<bool> visited;

void dfs(int v)
{
    // marked it visited
    visited[v] = true;
    cout << v << " "; // Process the vertex v

    // explored neigh if not visited yet
    for (int u : g[v])
    {
        if (!visited[u])
        {
            dfs(u);
        }
    }
}

int main()
{
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    g.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Depth-First Traversal
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
}

Time Complexity - O(E + V)