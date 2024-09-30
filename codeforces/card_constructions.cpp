#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_SIZE = 1e9;
vector <int> pyramid_sizes = {2};

void compute_pyramid_sizes()
{
    for (int i = 0; pyramid_sizes[i] <= MAX_SIZE; i++)
    {
        pyramid_sizes.push_back(pyramid_sizes[i] + 3 * i + 5);
    }
}

int find_max_pyramid_size_no_greater_than_n(int n)
{
    return *(upper_bound(pyramid_sizes.begin(), pyramid_sizes.end(), n) - 1);
}

int get_answer(int n)
{
    int result = 0;
    while (n > 1)
    {
        n -= find_max_pyramid_size_no_greater_than_n(n);
        result++;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    compute_pyramid_sizes();

    int t;
    cin >> t;
    while (t --> 0)
    {
        int n; cin >> n;
        cout << get_answer(n) << '\n';
    }
}
