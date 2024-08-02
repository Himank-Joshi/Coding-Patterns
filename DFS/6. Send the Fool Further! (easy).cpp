#include <bits/stdc++.h>
using namespace std;
int dfs(int src, vector<bool> &visited, vector<vector<pair<int, int>>> &adj)
{
    visited[src] = true;
    int maxcost = 0;
    for (auto it : adj[src])
    {
        int adjnode = it.first;
        int cost = it.second;
        if (visited[adjnode])
            continue;
        maxcost = max(maxcost, cost + dfs(adjnode, visited, adj));
    }
    return maxcost;
}
int main()
{
    int n;
    cin >> n;
    int temp = n - 1;
    vector<vector<pair<int, int>>> adj(n);
    vector<bool> visited(n);
    //<adjn,cost>
    while (temp--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    cout << dfs(0, visited, adj);
}