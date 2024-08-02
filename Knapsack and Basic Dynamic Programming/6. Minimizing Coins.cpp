#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // DP array to store the minimum number of coins needed for each value up to x
    vector<int> dp(x + 1, INT_MAX);

    // Base case: 0 coins are needed to make a sum of 0
    dp[0] = 0;

    // Iterate over each coin
    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= x; j++)
        {
            if (dp[j - coins[i]] != INT_MAX)
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }

    // Output the result
    if (dp[x] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[x] << endl;
    }

    return 0;
}
