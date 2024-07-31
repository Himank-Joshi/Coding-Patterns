#include <bits/stdc++.h>
using namespace std;
bool isgood(double len, vector<int> &a, int k)
{
    int num = 0;
    for (int i = 0; i < a.size(); i++)
        num += floor(a[i] / len);
    return num >= k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    double l = 0;   // good
    double r = 1e8; // bad;
    for (int i = 0; i < 70; i++)
    {
        double mid = (l + r) / 2;
        if (isgood(mid, a, k))
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(10) << l;
    return 0;
}
