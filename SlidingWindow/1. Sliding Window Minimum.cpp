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
    deque<int> dqmin;
    for (int i = 0; i < n; i++)
    {
        while (!dqmin.empty() && a[i] <= a[dqmin.back()])
            dqmin.pop_back();
        dqmin.push_back(i);
        if (i >= k - 1)
        {
            if (dqmin.front() <= i - k)
                dqmin.pop_front();
            cout << a[dqmin.front()] << " ";
        }
    }
}