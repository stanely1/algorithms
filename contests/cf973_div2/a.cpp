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
        int n, x, y;
        cin >> n >> x >> y;
        int result = (n + min(x, y) - 1) / min(x, y);
        cout << result << '\n';
    }
}
