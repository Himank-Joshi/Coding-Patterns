#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
long long pref_sum[N];
int a[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        // Reset pref_sum array for the new test case
        memset(pref_sum, 0, sizeof(pref_sum));

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++)
        {
            pref_sum[i] = pref_sum[i - 1] + a[i];
        }

        while (q--)
        {
            int l, r, k;
            cin >> l >> r >> k;

            long long sum = pref_sum[n];
            sum -= (pref_sum[r] - pref_sum[l - 1]);
            sum += ((r - l + 1) * k);

            if (sum % 2 == 0)
                cout << "NO";
            else
                cout << "YES";

            cout << "\n";
        }
    }

    return 0;
}
