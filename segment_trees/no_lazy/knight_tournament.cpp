#include <iostream>
#include <climits>
#include <stack>

constexpr int TREE_SIZE = 1<<19;

struct tree_node
{
    int val = 0, idx = 0;
};

tree_node tree[TREE_SIZE << 1];

struct query_t
{
    int l, r, x;
};

std::stack<query_t> queries;

void update(int l, int r, int x, int idx)
{
    l += TREE_SIZE - 1;
    r += TREE_SIZE + 1;

    while ((l >> 1) != (r >> 1))
    {
        if ((l & 1) == 0)
        {
            tree[l + 1] = {.val = x, .idx = idx};
        }
        if ((r & 1))
        {
            tree[r - 1] = {.val = x, .idx = idx};
        }

        l >>= 1;
        r >>= 1;
    }
}

int query(int p)
{
    int result_idx = 0;
    int result_val = 0;

    p += TREE_SIZE;

    while (p)
    {
        if (tree[p].idx > result_idx)
        {
            result_idx = tree[p].idx;
            result_val = tree[p].val;
        }
        p >>= 1;
    }

    return result_val;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    while (m --> 0)
    {
        int l, r, x;
        std::cin >> l >> r >> x;
        queries.push({l, r, x});
    }

    int idx = 0;

    while (not queries.empty())
    {
        auto [l, r, x] = queries.top();
        queries.pop();

        int prev_x = query(x);
        update(l, r, x, ++idx);
        update(x, x, prev_x, ++idx);
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << query(i) << ' ';
    }
    std::cout << '\n';
}
