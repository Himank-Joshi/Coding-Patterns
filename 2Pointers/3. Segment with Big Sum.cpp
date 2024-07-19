#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n;
    long long s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int left = 0, right = 0;
    long long current_sum = 0;
    int min_length = INT_MAX;

    while (right < n)
    {
        current_sum += a[right];

        while (current_sum >= s && left <= right)
        {
            min_length = min(min_length, right - left + 1);
            current_sum -= a[left];
            left++;
        }

        right++;
    }

    if (min_length == INT_MAX)
    {
        cout << 0 << endl; // No valid segment found
    }
    else
    {
        cout << min_length << endl;
    }

    return 0;
}
