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
        int n, a;
        cin >> n;

        long long result = 0;
        for (int i = 1; i <= n-2; i++)
        {
            cin >> a;
            result += a;
        }

        cin >> a;
        result -= a;
        cin >> a;
        result += a;

        cout << result << '\n';
    }
}
