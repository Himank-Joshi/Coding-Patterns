#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited, int prev)
{
    if (prev == 2)
        visited[node] = 1;
    else
        visited[node] = 2;
    for (auto adjnode : adj[node])
    {
        if (visited[adjnode] == visited[node])
            return false;
        if (visited[adjnode] == 0)
        {
            if (!dfs(adjnode, adj, visited, visited[node]))
                return false;
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            if (!dfs(i, adj, visited, 2))
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << visited[i] << " ";
    }
}