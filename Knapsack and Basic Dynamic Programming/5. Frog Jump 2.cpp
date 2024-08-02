#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Define a large value for initialization
const int INF = INT_MAX;

// Function to calculate the minimum cost using memoization
int minCost(int i, const vector<int> &h, int K, vector<int> &dp)
{
    if (i == 0)
        return 0; // Base case: cost to reach the first stone is 0
    if (dp[i] != -1)
        return dp[i]; // Return already computed value

    int cost = INF;
    for (int j = 1; j <= K; ++j)
    {
        if (i - j >= 0)
        {
            cost = min(cost, minCost(i - j, h, K, dp) + abs(h[i] - h[i - j]));
        }
    }

    return dp[i] = cost; // Store the computed result and return it
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> h(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> h[i];
    }

    vector<int> dp(N, -1); // Initialize dp array with -1 (indicating uncomputed states)
    cout << minCost(N - 1, h, K, dp) << endl;

    return 0;
}
