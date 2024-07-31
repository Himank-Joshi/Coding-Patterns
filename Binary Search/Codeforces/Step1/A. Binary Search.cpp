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
        bool found = false;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (a[mid] == target)
            {
                found = true;
                break;
            }
            else if (a[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (found)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
