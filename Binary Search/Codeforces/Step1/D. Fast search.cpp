#include <bits/stdc++.h>
using namespace std;
int findClosestToRight(int target, vector<int> &a)
{
    int n = a.size();
    int l = 0, r = n - 1;

    int ans = n;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] >= target)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
int findClosestToLeft(int target, vector<int> &a)
{
    int n = a.size();
    int l = 0, r = n - 1;

    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int k;
    cin >> k;
    while (k--)
    {
        int l, r, left, right;
        cin >> l >> r;
        left = findClosestToRight(l, a);
        if (left == n)
        {
            cout << 0 << " ";
            continue;
        }

        right = findClosestToLeft(r, a);
        if (right == -1)
        {
            cout << 0 << " ";
            continue;
        }
        cout << (right - left + 1) << " ";
    }

    return 0;
}
