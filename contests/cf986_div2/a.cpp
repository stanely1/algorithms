#include <bits/stdc++.h>
#include <ranges>
using namespace std;

const unordered_map<char, pair<int, int>> DIRECTIONS{
    {'N', { 0,  1}},
    {'S', { 0, -1}},
    {'W', {-1,  0}},
    {'E', { 1,  0}}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t --> 0)
    {
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;

        int x = 0, y = 0;

        bool result = false;

        for (int i = 0; i < 1000; i++)
        {
            for (auto dir : s)
            {
                if (x == a and y == b)
                {
                    result = true;
                }

                auto [dx, dy] = DIRECTIONS.at(dir);
                x += dx;
                y += dy;
            }
        }

        cout << (result ? "YES\n" : "NO\n");
    }
}
