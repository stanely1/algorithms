#include <bits/stdc++.h>
#include <ranges>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t --> 0)
    {
        int64_t n, b, c;
        cin >> n >> b >> c;

        if (b == 0)
        {
            if (c >= n)
            {
                cout << n << '\n';
            }
            else if (c >= n - 2)
            {
                cout << n - 1 << '\n';
            }
            else
            {
                cout << "-1\n";
            }
        }
        else
        {
            // Not working, working version in python because here I would need 128 bit int :(
            int64_t d = (n - c) / b;
            if ((n - c) % b != 0)
            {
                d++;
            }
            d = max(d, static_cast<int64_t>(0));
            cout << n - d << '\n';
        }
    }
}
