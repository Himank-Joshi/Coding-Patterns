#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int combinations(int targ, vector<int> &dp)
{
    if (targ == 0)
        return 1;
    if (dp[targ] != -1)
        return dp[targ];
    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (targ - i < 0)
            break;
        count = (count + combinations(targ - i, dp)) % mod;
    }
    return dp[targ] = count;
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << combinations(n, dp);
}