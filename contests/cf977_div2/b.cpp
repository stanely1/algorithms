#include <bits/stdc++.h>
#include <ranges>
using namespace std;

map<int, int> duplicates;
vector<int> a;

bool find_good_duplicate(int x, int& result)
{
    bool found_good_duplicate = false;
    for (auto& [d, cnt] : duplicates)
    {
        if (d > result)
        {
            break;
        }

        if ((result - d) % x == 0)
        {
            found_good_duplicate = true;
            if (--cnt == 0)
            {
                duplicates.erase(d);
            }
            result++;
            break;
        }
    }

    return found_good_duplicate;
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
        int n, x;
        cin >> n >> x;

        while (n --> 0)
        {
            int b;
            cin >> b;
            a.push_back(b);
        }

        ranges::sort(a);

        int result = 0;
        for (int i = 0; i < a.size(); i++)
        {
            while (a[i] > result and find_good_duplicate(x, result));

            if (a[i] > result)
            {
                break;
            }

            if (i > 0 and a[i] == a[i-1])
            {
                duplicates[a[i]]++;
            }
            else
            {
                result++;
            }
        }

        while (not duplicates.empty() and find_good_duplicate(x, result));

        cout << result << '\n';
        a.clear();
        duplicates.clear();
    }
}
