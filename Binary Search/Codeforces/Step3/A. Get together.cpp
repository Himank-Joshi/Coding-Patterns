#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Function to check if it's possible to gather everyone within time t
bool can_gather_at_time(double t, const vector<long long> &positions, const vector<long long> &speeds)
{
    double min_x = -1e18; // Large negative initial value
    double max_x = 1e18;  // Large positive initial value

    for (size_t i = 0; i < positions.size(); ++i)
    {
        double left_bound = positions[i] - t * speeds[i];
        double right_bound = positions[i] + t * speeds[i];
        min_x = max(min_x, left_bound);
        max_x = min(max_x, right_bound);
    }

    return min_x <= max_x;
}

// Function to find the minimum maximum time to gather everyone
double find_minimum_time(const vector<long long> &positions, const vector<long long> &speeds)
{
    double low = 0.0;
    double high = 1e18; // Large initial value
    double precision = 1e-6;

    while (high - low > precision)
    {
        double mid = (low + high) / 2.0;
        if (can_gather_at_time(mid, positions, speeds))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    return high;
}

int main()
{
    int n;
    cin >> n;
    //
    vector<long long> positions(n);
    vector<long long> speeds(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> positions[i] >> speeds[i];
    }

    double minimum_time = find_minimum_time(positions, speeds);
    cout << fixed << setprecision(6) << minimum_time << endl;

    return 0;
}
