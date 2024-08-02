#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countWays(int x, const vector<int> &coins, vector<int> &memo)
{
    if (x < 0)
        return 0; // No valid way to make a negative sum
    if (x == 0)
        return 1; // One way to make sum 0 (using no coins)
    if (memo[x] != -1)
        return memo[x]; // Return the cached result if available

    int ways = 0;
    for (int coin : coins)
    {
        ways = (ways + countWays(x - coin, coins, memo)) % MOD;
    }

    return memo[x] = ways; // Store the result in memo and return it
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }

    vector<int> memo(x + 1, -1); // Initialize memoization table with -1
    cout << countWays(x, coins, memo) << endl;

    return 0;
}
