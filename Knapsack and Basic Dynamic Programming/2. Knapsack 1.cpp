
#include <bits/stdc++.h>
using namespace std;

long long knapsack(int ind, int capacity, vector<int> &weight, vector<int> &value, vector<vector<long long>> &dp)
{
    if (capacity == 0 || ind == -1)
        return 0;
    if (dp[ind][capacity] != -1)
        return dp[ind][capacity];
    // take
    long long take = 0;
    if (weight[ind] <= capacity)
        take = value[ind] + knapsack(ind - 1, capacity - weight[ind], weight, value, dp);
    long long nottake = knapsack(ind - 1, capacity, weight, value, dp);
    return dp[ind][capacity] = max(nottake, take);
}
int main()
{
    int N, W;
    cin >> N >> W;
    vector<int> weight(N);
    vector<int> value(N);
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i];
    }
    vector<vector<long long>> dp(N, vector<long long>(W + 1, -1));
    cout << knapsack(N - 1, W, weight, value, dp);
}