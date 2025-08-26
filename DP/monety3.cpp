#include <bits/stdc++.h>
using namespace std;

constexpr int MAXS = 10000;
constexpr int MAXN = 100;
constexpr int MAXL = 10;
constexpr int MAXC = MAXN * MAXL;
constexpr int INF  = MAXC + 1;

int dp[2][MAXS + 1];
int coins[MAXC];

int main()
{
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int I = 0;
    while (n --> 0)
    {
        int s, l; cin >> s >> l;
        while (l --> 0)
        {
            coins[I++] = s;
        }
    }

    int s; cin >> s;

    for (int dp_id = 0; dp_id <= 1; dp_id++)
    {
        dp[dp_id][0] = 0;
        for (int i = 1; i <= s; i++)
        {
            dp[dp_id][i] = INF;
        }
    }

    int dp_id = 0;
    for (int i = 0; i < I; i++)
    {
        dp_id = 1 - dp_id;
        const int c = coins[i];
        for (int j = c; j <= s; j++)
        {
            dp[dp_id][j] = min(dp[1 - dp_id][j], dp[1 - dp_id][j - c] + 1);
        }
    }

    const int result = dp[dp_id][s];
    if (result == INF) cout << "NIE\n";
    else cout << result << '\n';
}
