#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, targ;
    cin >> n >> targ;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Map to store pairs and their indices
    unordered_map<int, pair<int, int>> pairs;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pairs[a[i] + a[j]] = {i + 1, j + 1}; // Store 1-based indices
        }
    }

    // Try to find two pairs that sum to targ
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int remaining = targ - a[i] - a[j];
            if (pairs.find(remaining) != pairs.end())
            {
                pair<int, int> p = pairs[remaining];
                // Ensure the indices are distinct
                if (p.first != i + 1 && p.first != j + 1 && p.second != i + 1 && p.second != j + 1)
                {
                    cout << p.first << " " << p.second << " " << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
