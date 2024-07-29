#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    int l = 0, distinct = 0;
    unordered_map<int, int> map;
    for (int r = 0; r < n; r++)
    {
        map[a[r]]++;
        if (map[a[r]] == 1)
            distinct++;
        while (distinct > k && l <= r)
        {
            map[a[l]]--;
            if (map[a[l]] == 0)
                distinct--;
            l++;
        }
        ans += (r - l + 1);
    }
    cout << ans;
}