#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Redirect input and output to files
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    unordered_map<int, int> map;
    map[0] = 0; // Initialize the map with the base case for the prefix sum 0
    long long sum = 0;
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        int mod = sum % 7;
        if (map.find(mod) != map.end())
        {
            ans = max(ans, i - map[mod]); // Update the maximum length
        }
        else
        {
            map[mod] = i; // Store the first occurrence of this mod value
        }
    }

    cout << ans << endl;

    return 0;
}
