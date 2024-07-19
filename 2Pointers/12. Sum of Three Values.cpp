#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Element
{
    int value;
    int index;
};

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    vector<Element> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].value;
        a[i].index = i + 1; // Store 1-based index
    }

    // Sort the array based on values
    sort(a.begin(), a.end(), [](const Element &e1, const Element &e2)
         { return e1.value < e2.value; });

    for (int i = 0; i < n - 2; i++)
    {
        long long target = x - a[i].value;
        int left = i + 1;
        int right = n - 1;

        // Use two-pointer technique to find the remaining two values
        while (left < right)
        {
            long long current_sum = a[left].value + a[right].value;
            if (current_sum == target)
            {
                cout << a[i].index << " " << a[left].index << " " << a[right].index << endl;
                return 0;
            }
            else if (current_sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
