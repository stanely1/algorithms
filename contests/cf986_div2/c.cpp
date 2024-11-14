#include <bits/stdc++.h>
#include <ranges>
using namespace std;

constexpr int MAXN = 2e5 + 4;

int arr[MAXN], prefix_count[MAXN], suffix_count[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t --> 0)
    {
        int n, m ,v;
        cin >> n >> m >> v;

        int64_t sum = 0;
        prefix_count[0] = suffix_count[n+1] = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sum += arr[i];

            prefix_count[i] = prefix_count[i-1];
            if (sum >= v)
            {
                sum = 0;
                prefix_count[i]++;
            }
        }

        sum = 0;
        for (int i = n; i > 0; i--)
        {
            sum += arr[i];
            suffix_count[i] = suffix_count[i+1];
            if (sum >= v)
            {
                sum = 0;
                suffix_count[i]++;
            }
        }

        if (prefix_count[n] < m or suffix_count[1] < m)
        {
            cout << "-1\n";
            continue;
        }

        sum = 0;
        int64_t max_sum = 0;
        for (int i = 1, j = 0; i <= n and j < n;)
        {
            if (prefix_count[i-1] + suffix_count[j+2] >= m)
            {
                sum += arr[++j];
                max_sum = max(sum, max_sum);
                // cerr << i << " " << j << " -> value: " << sum << '\n';
            }
            else
            {
                sum -= arr[i++];
            }
        }

        cout << max_sum << '\n';
    }
}
