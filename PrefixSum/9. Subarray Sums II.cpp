#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<long long, long long> prefix_count;
    long long prefix_sum = 0;
    long long count = 0;

    // Initialize the prefix_count with 0 prefix sum occurring once.
    prefix_count[0] = 1;

    for (int i = 0; i < n; i++)
    {
        prefix_sum += a[i];
        if (prefix_count.count(prefix_sum - x))
        {
            count += prefix_count[prefix_sum - x];
        }
        prefix_count[prefix_sum]++;
    }

    cout << count << endl;

    return 0;
}
