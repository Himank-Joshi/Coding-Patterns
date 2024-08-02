#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int func(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row < 0 || col < 0 || grid[row][col] == 1)
        return 0;
    if (dp[row][col] != -1)
        return dp[row][col];
    if (row == 0 && col == 0)
        return 1;
    int left = func(row, col - 1, grid, dp);
    int right = func(row - 1, col, grid, dp);
    return dp[row][col] = (left + right) % mod;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++)
        {
            if (line[j] == '*')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << func(n - 1, n - 1, grid, dp);
    // grid 1=obs 0= no obs
}