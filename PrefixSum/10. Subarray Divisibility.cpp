#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<int, long long> prefix_count;
    long long prefix_sum = 0;
    long long count = 0;

    // Initialize the prefix_count with 0 prefix sum occurring once.
    prefix_count[0] = 1;

    for (int i = 0; i < n; i++)
    {
        prefix_sum += a[i];
        // Calculate the modulo with n and adjust for negative values
        int mod = ((prefix_sum % n) + n) % n;
        if (prefix_count.find(mod) != prefix_count.end())
        {
            count += prefix_count[mod];
        }
        prefix_count[mod]++;
    }

    cout << count << endl;

    return 0;
}
