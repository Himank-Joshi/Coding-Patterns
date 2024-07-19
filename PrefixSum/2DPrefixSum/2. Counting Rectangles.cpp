#include <bits/stdc++.h>
using namespace std;

const int MAX_DIM = 1001;
long long area[MAX_DIM][MAX_DIM], pre[MAX_DIM][MAX_DIM];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        // Reset arrays for each test case
        memset(area, 0, sizeof(area));
        memset(pre, 0, sizeof(pre));

        int n, q;
        cin >> n >> q;

        // Read the rectangles and accumulate their areas
        for (int i = 0; i < n; i++)
        {
            int h, w;
            cin >> h >> w;
            area[h][w] += (long long)h * w; // Accumulate the area
        }

        // Calculate the 2D prefix sum array
        for (int i = 1; i < MAX_DIM; i++)
        {
            for (int j = 1; j < MAX_DIM; j++)
            {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + area[i][j];
            }
        }

        // Process each query
        for (int i = 0; i < q; i++)
        {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;

            // Calculate the total area of rectangles that fit the criteria
            long long total_area = pre[hb - 1][wb - 1] - pre[hs][wb - 1] - pre[hb - 1][ws] + pre[hs][ws];
            cout << total_area << "\n";
        }
    }

    return 0;
}
