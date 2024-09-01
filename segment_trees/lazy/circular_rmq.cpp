#include <iostream>
#include <cstdint>
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>

constexpr int TREE_SIZE = 1<<18;

std::int64_t tree[TREE_SIZE << 1];
std::int64_t lazy[TREE_SIZE << 1];

void propagate(int node)
{
    if (node >= TREE_SIZE or lazy[node] == 0)
    {
        return;
    }

    tree[node << 1] += lazy[node];
    lazy[node << 1] += lazy[node];

    tree[(node << 1) + 1] += lazy[node];
    lazy[(node << 1) + 1] += lazy[node];

    lazy[node] = 0;
}

void update(int l, int r, int v, int node = 1, int node_l = 0, int node_r = TREE_SIZE - 1)
{
    if (r < node_l or node_r < l)
    {
        return;
    }
    if (l <= node_l and node_r <= r)
    {
        tree[node] += v;
        lazy[node] += v;
        return;
    }

    propagate(node);

    int m = (node_l + node_r) / 2;
    update(l, r, v, node << 1, node_l, m);
    update(l, r, v, (node << 1) + 1, m + 1, node_r);

    tree[node] = std::min(tree[node << 1], tree[(node << 1) + 1]);
}

std::int64_t query(int l, int r, int node = 1, int node_l = 0, int node_r = TREE_SIZE - 1)
{
    if (r < node_l or node_r < l)
    {
        return std::numeric_limits<std::int64_t>::max();
    }
    if (l <= node_l and node_r <= r)
    {
        return tree[node];
    }

    propagate(node);

    int m = (node_l + node_r) / 2;
    return std::min(query(l, r, node << 1, node_l, m), query(l, r, (node << 1) + 1, m + 1, node_r));
}

void build_tree()
{
    for (int i = TREE_SIZE - 1; i > 0; i--)
    {
        tree[i] = std::min(tree[i << 1], tree[(i << 1) + 1]);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> tree[TREE_SIZE + i];
    }

    build_tree();

    int m;
    std::cin >> m;
    std::string empty_line;
    std::getline(std::cin, empty_line);

    while (m --> 0)
    {
        std::vector<int> input;
        std::string line;
        std::getline(std::cin, line);

        std::stringstream ss{line};
        int x;

        while (ss >> x)
        {
            input.push_back(x);
        }

        if (input.size() == 2)
        {
            auto [l, r] = std::tuple{input.at(0), input.at(1)};
            if (l <= r)
            {
                std::cout << query(l, r) << '\n';
            }
            else
            {
                std::cout << std::min(query(l, n - 1), query(0, r)) << '\n';
            }
        }
        else
        {
            auto [l, r, v] = std::tuple{input.at(0), input.at(1), input.at(2)};
            if (l <= r)
            {
                update(l, r, v);
            }
            else
            {
                update(l, n - 1, v);
                update(0, r, v);
            }
        }
    }
}
