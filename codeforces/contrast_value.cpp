#include <bits/stdc++.h>
using namespace std;

vector<int> v;

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

        while (n --> 0)
        {
            int x;
            cin >> x;
            if (v.empty() or x != v.back())
            {
                v.push_back(x);
            }
        }

        int result = 2;

        if (v.size() == 1)
        {
            result = 1;
        }
        else
        {
            bool is_increasing = v[0] <= v[1];
            for (int i = 2; i < v.size(); i++)
            {
                bool is_monotonicity_change = is_increasing ? v[i-1] > v[i] : v[i - 1] < v[i];
                if (is_monotonicity_change)
                {
                    result++;
                    is_increasing ^= 1;
                }
            }
        }

        cout << result << '\n';
        v.clear();
    }
}
