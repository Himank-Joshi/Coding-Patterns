#include <iostream>
using namespace std;

long long n, x, y;

bool good(long long time)
{
    int copycount = 0;
    time -= min(x, y);
    if (time >= 0)
        copycount++;
    copycount += time / x;
    copycount += time / y;
    return copycount >= n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> y;

    long long l = 1;             // l is bad
    long long r = max(x, y) * n; // r is good

    while (r > l + 1)
    {
        long long m = (l + r) / 2;
        if (good(m))
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }

    cout << r << "\n";
    return 0;
}
