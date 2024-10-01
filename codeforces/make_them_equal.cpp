#include <bits/stdc++.h>
using namespace std;

int compute_result(const int n, const unordered_set<int>& positions)
{
    for (int i = 1; i <= n; i++)
    {
        bool is_every_x_in_positions = true;
        for (int x = i; x <= n; x += i)
        {
            if (not positions.contains(x))
            {
                is_every_x_in_positions = false;
                break;
            }
        }

        if (is_every_x_in_positions)
        {
            return i;
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --> 0)
    {
        int n;
        char c;
        cin >> n >> c;

        unordered_set<int> c_positions;

        for(int i = 1; i <= n; i++)
        {
            char x;
            cin >> x;
            if (x == c)
            {
                c_positions.insert(i);
            }
        }

        int result = compute_result(n, c_positions);

        switch (result)
        {
            case 0:
                cout << "2\n" << n << ' ' << n - 1 << '\n';
                break;
            case 1:
                cout << "0\n";
                break;
            default:
                cout << "1\n" << result << '\n';
                break;
        }
    }
}
