#include <bits/stdc++.h>
#include <ranges>
using namespace std;

constexpr int TAXI_SIZE = 4;

deque<int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n --> 0)
    {
        int x;
        cin >> x;
        s.push_back(x);
    }

    ranges::sort(s);

    int result = 0;
    while (not s.empty())
    {
        int sum = 0;
        while (not s.empty() and sum + s.back() <= TAXI_SIZE)
        {
            sum += s.back();
            s.pop_back();
        }
        while (not s.empty() and sum + s.front() <= TAXI_SIZE)
        {
            sum += s.front();
            s.pop_front();
        }
        result++;
    }

    cout << result << '\n';
}
