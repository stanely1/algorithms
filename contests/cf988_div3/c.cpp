#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 4e5 + 4;

vector<bool> is_composite(MAXN, false);

void sieve()
{
    is_composite[2] = false;
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (not is_composite[i])
        {
            for (int j = (i << 1); j <= MAXN; j += i)
            {
                is_composite[j] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve();

    int t;
    cin >> t;
    while (t --> 0)
    {
        int n;
        cin >> n;

        if (n < 5)
        {
            cout << "-1\n";
            continue;
        }

        int last_odd = n - ((n & 1) == 0);
        int first_even = 0;

        for (int i = 2; i <= n; i += 2)
        {
            if (is_composite[last_odd + i])
            {
                first_even = i;
                break;
            }
        }

        if (first_even == 0)
        {
            cout << "-1\n";
        }

        for (int i = 1; i <= last_odd; i += 2)
        {
            cout << i << ' ';
        }

        cout << first_even << ' ';

        for (int i = 2; i <= n; i += 2)
        {
            if (i != first_even)
            {
                cout << i << ' ';
            }
        }

        cout << '\n';
    }
}
