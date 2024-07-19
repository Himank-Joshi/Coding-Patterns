#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    // Sorting the array b
    sort(b.begin() + 1, b.end());

    // Creating prefix sums for both arrays
    vector<long long> presum1(n + 1), presum2(n + 1);

    for (int i = 1; i <= n; i++)
    {
        presum1[i] = presum1[i - 1] + a[i];
        presum2[i] = presum2[i - 1] + b[i];
    }

    int m;
    cin >> m;
    while (m--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            cout << presum1[r] - presum1[l - 1] << "\n";
        }
        else
        {
            cout << presum2[r] - presum2[l - 1] << "\n";
        }
    }

    return 0;
}
