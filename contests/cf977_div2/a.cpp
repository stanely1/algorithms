#include <bits/stdc++.h>
#include <ranges>
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
        deque<int> a(n);

        for (auto& x : a)
        {
            cin >> x;
        }

        ranges::sort(a);
        while (a.size() > 1)
        {
            int x = a.front();
            a.pop_front();
            int y = a.front();
            a.pop_front();

            a.push_front((x + y) / 2);
        }

        cout << a.front() << '\n';
    }
}
