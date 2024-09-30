#include <bits/stdc++.h>
#include <ranges>
using namespace std;

vector<pair<int, int>> pairs;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while (n --> 0)
    {
        int a, b;
        cin >> a >> b;
        pairs.push_back({a, b});
    }

    ranges::sort(pairs);
    auto second_elements = pairs | ranges::views::transform([](const auto& p) { return p.second; });

    if (ranges::is_sorted(second_elements))
    {
        cout << "Poor Alex\n";
    }
    else
    {
        cout << "Happy Alex\n";
    }
}
