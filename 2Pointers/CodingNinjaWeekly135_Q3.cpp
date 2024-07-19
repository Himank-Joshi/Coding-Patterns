// binary array finding subarrays with exactly k inversions
// idea exactly k= f(k)-f(k-1) where f()finds sub with atmost k inverion
#include <bits/stdc++.h>
using namespace std;
long long func(int n, int k, vector<int> &a)
{
    int count1 = 0;
    int count0 = 0;
    long long count = 0;
    int inv = 0;
    int l = 0;
    for (int r = 0; r < n; r++)
    {
        if (a[r] == 0)
        {
            count0++;
            inv += count1;
        }
        else
        {
            count1++;
        }
        while (inv > k)
        {
            if (a[l] == 0)
                count0--;
            else
            {
                count1--;
                inv -= count0;
            }
            l++;
        }
        count += (r - l + 1);
    }
    return count;
}
long long kInversions(int n, int k, vector<int> &a)
{
    // Write your code here.
    return func(n, k, a) - func(n, k - 1, a);
}