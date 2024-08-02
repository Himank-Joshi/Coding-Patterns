
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int coinways(int ind, int target, vector<int> &coins, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (ind == 0)
    {
        return (target % coins[0] == 0) ? 1 : 0;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];
    // take
    int take = 0;
    if (coins[ind] <= target)
        take = coinways(ind, target - coins[ind], coins, dp) % mod;
    int nottake = coinways(ind - 1, target, coins, dp) % mod;
    return dp[ind][target] = (take + nottake) % mod;
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    // base cases
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    for (int tar = 0; tar <= x; tar++)
    {
        dp[0][tar] = (tar % coins[0] == 0) ? 1 : 0;
    }
    // rec logic
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= x; target++)
        {
            int take = 0;
            if (coins[ind] <= target)
                take = dp[ind][target - coins[ind]];
            int nottake = dp[ind - 1][target];
            dp[ind][target] = (take + nottake) % mod;
        }
    }
    cout << dp[n - 1][x];
}