#include <bits/stdc++.h>
using namespace std;
void dfs(int r, int c, vector<vector<int>> &grid)
{
    grid[r][c] = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int newr = r + dr[i];
        int newc = c + dc[i];
        if (newr < 0 || newr >= grid.size() || newc < 0 || newc >= grid[0].size() || grid[newr][newc] == 0)
            continue;
        dfs(newr, newc, grid);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(i, j, grid);
                count++;
            }
        }
    }
    cout << count;
}