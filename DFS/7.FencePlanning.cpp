#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, int &maxr, int &maxc, int &minr, int &minc, unordered_map<int, pair<int, int>> &map)
{
    visited[node] = true;
    auto cord = map[node];
    int r = cord.first;
    int c = cord.second;
    maxr = max(maxr, r);
    maxc = max(maxc, c);
    minr = min(minr, r);
    minc = min(minc, c);
    for (int adjnode : adj[node])
    {
        if (visited[adjnode])
            continue;
        dfs(adjnode, adj, visited, maxr, maxc, minr, minc, map);
    }
}

int main()
{
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");

    int n, m;
    fin >> n >> m;

    unordered_map<int, pair<int, int>> map;
    for (int i = 1; i <= n; i++)
    {
        int r, c;
        fin >> r >> c;
        map[i] = {r, c};
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    int ans = INT_MAX;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int maxr = INT_MIN, maxc = INT_MIN, minr = INT_MAX, minc = INT_MAX;
            dfs(i, adj, visited, maxr, maxc, minr, minc, map);
            int per = 2 * ((maxr - minr) + (maxc - minc));
            ans = min(ans, per);
        }
    }

    fout << ans << endl;
    return 0;
}
