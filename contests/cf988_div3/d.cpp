#include <bits/stdc++.h>
using namespace std;

constexpr int TREE_SIZE = 1<<20;

pair<int, int> tree[TREE_SIZE << 1];

vector<pair<int, int>> hurdles;
vector<pair<int, int>> powerups;

multiset<int> positions;
unordered_map<int, int> num;

void update(int x, int v)
{
    x += TREE_SIZE;
    tree[x] = {x - TREE_SIZE, v};

    x >>= 1;
    while (x)
    {
        tree[x] = tree[x << 1].second > tree[(x << 1) + 1].second ? tree[x << 1] : tree[(x << 1) + 1];
        x >>= 1;
    }
}

pair<int, int> query(int r)
{
    int l = TREE_SIZE;
    r += TREE_SIZE + 1;

    pair<int, int> result = {0, 0};

    while ((l >> 1) != (r >> 1))
    {
        if ((l & 1) == 0)
        {
            if (tree[l + 1].second > result.second)
            {
                result = tree[l + 1];
            }
        }
        if ((r & 1))
        {
            if (tree[r - 1].second > result.second)
            {
                result = tree[r - 1];
            }
        }

        l >>= 1;
        r >>= 1;
    }

    return result;
}

void clean(int n)
{
    hurdles.clear();
    powerups.clear();
    positions.clear();
    num.clear();

    for (int i = 1; i <= n; i++)
    {
        update(i, 0);
    }
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
        int n, m, L;
        cin >> n >> m >> L;

        // read input
        for (int i = 0; i < n; i++)
        {
            int l, r; cin >> l >> r;
            hurdles.push_back({l, r});
            positions.insert(l);
            positions.insert(r);
        }

        for (int i = 0; i < m; i++)
        {
            int x, v; cin >> x >> v;
            powerups.push_back({x, v});
            positions.insert(x);
        }

        // convert positions to permutation
        int idx = 0;
        for (auto x : positions)
        {
            num[x] = ++idx;
        }

        // build tree
        int j = 0;
        for (int i = 0; i < m; i++)
        {
            auto [x, v] = powerups[i];
            if (i > 0 and x == powerups[i-1].first)
            {
                j++;
                update(num[x] - j, v);
            }
            else
            {
                j = 0;
                update(num[x], v);
            }
        }

        // mięsko
        int jump_power = 1;
        int powerups_collected = 0;
        bool success = true;

        for (auto [l, r] : hurdles)
        {
            while (jump_power < r - l + 2)
            {
                auto [x, v] = query(num[l]);
                // cerr << "hurdle " << l << ' ' << r << " jump: " << jump_power << " query result " << x << ' ' << v << '\n';
                if (v == 0)
                {
                    success = false;
                    break;
                }

                powerups_collected++;
                jump_power += v;
                update(x, 0);
            }

            if (not success)
            {
                break;
            }
        }

        cout << (success ? powerups_collected : -1) << '\n';

        clean(idx);
    }
}
