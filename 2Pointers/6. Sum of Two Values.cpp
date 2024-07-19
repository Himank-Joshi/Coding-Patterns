#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;
    // used map instead of 2 pointers
    vector<int> a(n);
    unordered_map<long long, int> value_to_index;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        long long complement = x - a[i];
        if (value_to_index.find(complement) != value_to_index.end())
        {
            cout << value_to_index[complement] + 1 << " " << i + 1 << endl;
            return 0;
        }
        value_to_index[a[i]] = i;
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
