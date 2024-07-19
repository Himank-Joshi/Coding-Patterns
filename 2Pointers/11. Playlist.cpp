#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> playlist(n);
    for (int i = 0; i < n; i++)
    {
        cin >> playlist[i];
    }

    unordered_map<int, int> song_count;
    int max_length = 0, left = 0;

    for (int right = 0; right < n; right++)
    {
        song_count[playlist[right]]++;

        // If we encounter a duplicate song, shrink the window from the left
        while (song_count[playlist[right]] > 1)
        {
            song_count[playlist[left]]--;
            left++;
        }

        // Update the maximum length of unique song sequence
        max_length = max(max_length, right - left + 1);
    }

    cout << max_length << endl;
    return 0;
}
