#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (k--)
    {
        int target;
        cin >> target;
        int l = 0, r = n - 1;
        int ans = n + 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (a[mid] >= target)
            {
                ans = mid + 1;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
