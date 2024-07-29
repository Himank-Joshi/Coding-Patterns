#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long ans = 0;
    int l = 0;
    deque<int> dqmax;
    deque<int> dqmin;

    for (int r = 0; r < n; r++)
    {
        // add r to current window
        while (!dqmax.empty() && a[r] >= a[dqmax.back()])
            dqmax.pop_back();
        dqmax.push_back(r);

        while (!dqmin.empty() && a[r] <= a[dqmin.back()])
            dqmin.pop_back();
        dqmin.push_back(r);

        while (a[dqmax.front()] - a[dqmin.front()] > k)
        {
            l++;
            if (dqmax.front() < l)
                dqmax.pop_front();
            if (dqmin.front() < l)
                dqmin.pop_front();
        }

        ans += (r - l + 1);
    }

    cout << ans << endl;
    return 0;
}
