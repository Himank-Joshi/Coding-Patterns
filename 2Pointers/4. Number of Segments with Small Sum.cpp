#include <iostream>
#include <vector>
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

    long long current_sum = 0;
    int left = 0;
    long long count_good_segments = 0;

    for (int right = 0; right < n; right++)
    {
        current_sum += a[right];

        while (current_sum > s && left <= right)
        {
            current_sum -= a[left];
            left++;
        }

        // All subarrays ending at 'right' with start from 'left' to 'right' are good.
        count_good_segments += (right - left + 1);
    }

    cout << count_good_segments << endl;
    return 0;
}
