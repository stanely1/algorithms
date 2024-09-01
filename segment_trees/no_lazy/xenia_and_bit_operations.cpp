#include <iostream>
#include <vector>
#include <cstdint>

constexpr bool OR = false;
constexpr bool XOR = true;

std::uint32_t tree_size;

std::vector<std::uint32_t> tree;
std::vector<bool> operation;

void build_tree()
{
    for (auto i = tree_size - 1; i > 0; i--)
    {
        if (operation[i << 1] == OR)
        {
            tree[i] = tree[i << 1] | tree[(i << 1) + 1];
            operation[i] = XOR;
        }
        else
        {
            tree[i] = tree[i << 1] ^ tree[(i << 1) + 1];
            operation[i] = OR;
        }
    }
}

void update(std::uint32_t pos, std::uint32_t val)
{
    pos += tree_size;
    tree[pos] = val;
    pos >>= 1;

    while (pos)
    {
        if (operation[pos << 1] == OR)
        {
            tree[pos] = tree[pos << 1] | tree[(pos << 1) + 1];
        }
        else
        {
            tree[pos] = tree[pos << 1] ^ tree[(pos << 1) + 1];
        }
        pos >>= 1;
    }
}

std::uint32_t query()
{
    return tree[1];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    tree_size = 1 << n;
    tree = std::vector<std::uint32_t>(tree_size << 1);
    operation = std::vector<bool>(tree_size << 1);

    for (auto i = 0u; i < tree_size; i++)
    {
        std::cin >> tree[tree_size + i];
        operation[tree_size + i] = OR;
    }

    build_tree();

    while (m --> 0)
    {
        std::uint32_t pos, val;
        std::cin >> pos >> val;
        update(pos - 1, val);
        std::cout << query() << '\n';
    }
}
