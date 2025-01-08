#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> graph;
vector<bool> visited;
vector<int> dist;

void bfs(int start)
{
    queue<int> q;

    // update distance and push start in queue
    dist[start] = 0;
    q.push(start);

    // while not empty
    while (!q.empty())
    {
        // take top and pop it
        int current = q.front();
        q.pop();
        cout << current << " ";

        // if visited already then contiue else mark it true and proceed further
        if (visited[current])
        {
            continue;
        }
        visited[current] = 1;

        // explore the neighbors
        for (int neighbor : graph[current])
        {
            // if dist can be made less than do it
            if (dist[neighbor] > dist[current] + 1)
            {
                dist[neighbor] = dist[current] + 1;
                q.push(neighbor);
            }
        }
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        // Initialize graph, visited, and dist arrays
        graph.assign(n + 1, vector<int>());
        visited.assign(n + 1, 0);
        dist.assign(n + 1, 1e9);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int start = 1;
        bfs(start);

        // Print distances from the start node to all other nodes
        for (int i = 1; i <= n; i++)
        {
            cout << "Distance from node " << start << " to node " << i << " is " << dist[i] << endl;
        }
    }
}

O(E + V)