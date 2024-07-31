#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Assistant
{
    int t, z, y;
};

// Function to calculate the number of balloons an assistant can inflate in given time
int balloons_inflated(int time, const Assistant &assistant)
{
    int cycle_time = assistant.t * assistant.z + assistant.y;
    int cycles = time / cycle_time;
    int remaining_time = time % cycle_time;
    int balloons = cycles * assistant.z;
    balloons += min(remaining_time / assistant.t, assistant.z);
    return balloons;
}

// Function to check if it's possible to inflate all balloons in given time
bool can_inflate_all(int time, const vector<Assistant> &assistants, int m)
{
    int total_balloons = 0;
    for (const auto &assistant : assistants)
    {
        total_balloons += balloons_inflated(time, assistant);
        if (total_balloons >= m)
            return true;
    }
    return total_balloons >= m;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<Assistant> assistants(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> assistants[i].t >> assistants[i].z >> assistants[i].y;
    }

    // Binary search for the minimum time
    int low = 0, high = 1e9, best_time = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (can_inflate_all(mid, assistants, m))
        {
            best_time = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    // Calculate the number of balloons each assistant inflates in the best_time
    vector<int> result(n);
    int total_balloons = 0;
    for (int i = 0; i < n; ++i)
    {
        result[i] = balloons_inflated(best_time, assistants[i]);
        total_balloons += result[i];
    }

    // Adjust the results if we have inflated more balloons than needed
    for (int i = 0; i < n && total_balloons > m; ++i)
    {
        int extra = min(total_balloons - m, result[i]);
        result[i] -= extra;
        total_balloons -= extra;
    }

    cout << best_time << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
