#include <bits/stdc++.h>
using namespace std;

int func(int ind, int priceleft, vector<int> &prices, vector<int> &pages, vector<vector<int>> &dp)
{
    if (priceleft == 0 || ind == 0)
        return 0;
    if (dp[ind][priceleft] != -1)
        return dp[ind][priceleft];
    int take = 0;
    if (prices[ind - 1] <= priceleft)
        take = pages[ind - 1] + func(ind - 1, priceleft - prices[ind - 1], prices, pages, dp);
    int notake = func(ind - 1, priceleft, prices, pages, dp);
    return dp[ind][priceleft] = max(take, notake);
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    // shift 1 in dp for bot up
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    // base cases
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int p = 0; p <= x; p++)
        dp[0][p] = 0;
    for (int ind = 1; ind <= n; ind++)
    {
        for (int priceleft = 0; priceleft <= x; priceleft++)
        {
            int take = 0;
            if (prices[ind - 1] <= priceleft)
                take = pages[ind - 1] + dp[ind - 1][priceleft - prices[ind - 1]];
            int notake = dp[ind - 1][priceleft];
            dp[ind][priceleft] = max(take, notake);
        }
    }
    cout << dp[n][x];
}