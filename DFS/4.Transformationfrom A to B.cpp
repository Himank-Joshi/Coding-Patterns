#include <iostream>
#include <vector>

using namespace std;

// DFS function to find the sequence of transformations
bool dfs(long long a, long long b, vector<long long> &sequence)
{
    sequence.push_back(a);

    if (a == b)
    {
        return true;
    }

    if (a > b)
    {
        sequence.pop_back();
        return false;
    }

    // Try to multiply by 2
    if (dfs(2 * a, b, sequence))
    {
        return true;
    }

    // Try to append 1
    if (dfs(10 * a + 1, b, sequence))
    {
        return true;
    }

    sequence.pop_back();
    return false;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    vector<long long> sequence;

    if (dfs(a, b, sequence))
    {
        cout << "YES" << endl;
        cout << sequence.size() << endl;
        for (long long x : sequence)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
