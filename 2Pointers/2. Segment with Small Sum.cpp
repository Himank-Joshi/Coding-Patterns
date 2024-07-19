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

    int left = 0;
    int right = 0;
    long long current_sum = 0;
    int max_length = 0;

    while (right < n)
    {
        current_sum += a[right];
        while (current_sum > s && left <= right)
        {
            current_sum -= a[left];
            left++;
        }
        max_length = max(max_length, right - left + 1);
        right++;
    }

    cout << max_length << endl;
    return 0;
}
