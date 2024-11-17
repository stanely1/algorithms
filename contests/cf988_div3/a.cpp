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

        unordered_map<int, int> cnt;

        for (int i = 0; i < n; i++)
        {
            int x; cin >> x;
            cnt[x]++;
        }

        int result = 0;

        for (auto [x, c] : cnt)
        {
            result += (c >> 1);
        }

        cout << result << '\n';
    }
}
