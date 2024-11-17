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
        int k;
        cin >> k;

        int nm = k - 2;

        unordered_multiset<int> numbers;

        for (int i = 0; i < k; i++)
        {
            int x; cin >> x;
            numbers.insert(x);
        }

        for (auto n : numbers)
        {
            if (nm % n == 0 and numbers.contains(nm / n))
            {
                if (nm / n != n or numbers.count(n) > 1)
                {
                    cout << n << ' ' << nm / n << '\n';
                    break;
                }
            }
        }
    }
}
