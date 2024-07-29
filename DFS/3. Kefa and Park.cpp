#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];

// Function to perform DFS
int dfs(int u, int curr, int max_cats, vector<int> &cat)
{
    vis[u] = true;
    if (cat[u] == 1)
        curr++;
    else
        curr = 0;

    if (curr > max_cats)
        return 0;

    // Check if the current node is a leaf
    bool is_leaf = true;
    int count = 0;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            is_leaf = false;
            count += dfs(v, curr, max_cats, cat);
        }
    }

    // If it is a leaf and valid path, increment count
    if (is_leaf)
        return 1;

    return count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, max_cats;
    cin >> n >> max_cats;

    vector<int> cat(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> cat[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Start DFS from the root node (1)
    int curr = 0;
    int result = dfs(1, curr, max_cats, cat);
    cout << result << '\n';

    return 0;
}
