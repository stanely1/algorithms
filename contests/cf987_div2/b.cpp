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

        bool result = true;
        for (int i = 1; i <= n; i++)
        {
            int p; cin >> p;
            if (abs(p - i) > 1)
            {
                result = false;
            }
        }

        cout << (result ? "YES\n" : "NO\n");
    }
}
