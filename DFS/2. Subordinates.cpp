#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
bool vis[N];
int dfs(int u, vector<int> &ans)
{
    vis[u] = true;
    int count = 0;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            count += 1;
            count += dfs(v, ans);
        }
    }
    ans[u] = count;
    return count;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int boss;
        cin >> boss;
        g[boss].push_back(i);
    }
    vector<int> ans(n + 1, 0);
    dfs(1, ans);
    for (int u = 1; u <= n; u++)
    {
        cout << ans[u] << " ";
    }
}
