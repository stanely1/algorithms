#include <bits/stdc++.h>
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
        int n;
        cin >> n;

        vector<int> h(n);
        cin >> h[0];

        int longest_equal_h = 1;
        int current_equal_h = 1;

        for (int i = 1; i < n; i++)
        {
            cin >> h[i];
            if (h[i] == h[i-1])
            {
                current_equal_h++;
            }
            else
            {
                current_equal_h = 1;
            }
            longest_equal_h = max(longest_equal_h, current_equal_h);
        }

        cout << n - longest_equal_h << '\n';
    }
}
