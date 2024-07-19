#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 7;

int a[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // For file input/output
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> presum(n + 1, vector<int>(3, 0));

    for (int i = 1; i <= n; i++)
    {
        presum[i] = presum[i - 1];
        presum[i][a[i] - 1]++;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << presum[r][0] - presum[l - 1][0] << " ";
        cout << presum[r][1] - presum[l - 1][1] << " ";
        cout << presum[r][2] - presum[l - 1][2] << "\n";
    }

    return 0;
}
