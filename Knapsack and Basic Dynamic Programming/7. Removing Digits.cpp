#include <bits/stdc++.h>
using namespace std;

int dp[1000001]; // Memoization array

int minSteps(int n)
{
    // Base case: If n is 0, no steps are required
    if (n == 0)
        return 0;

    // If already computed, return the stored result
    if (dp[n] != -1)
        return dp[n];

    int min_steps = INT_MAX;
    int num = n;

    // Consider each digit in the current number
    while (num > 0)
    {
        int digit = num % 10;
        if (digit > 0)
        { // Ensure we only subtract non-zero digits
            min_steps = min(min_steps, 1 + minSteps(n - digit));
        }
        num /= 10;
    }

    // Store the result and return
    return dp[n] = min_steps;
}

int main()
{
    int n;
    cin >> n;

    // Initialize the memoization array with -1
    memset(dp, -1, sizeof(dp));

    cout << minSteps(n) << endl;
    return 0;
}
