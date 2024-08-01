#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

struct Event
{
    enum Type
    {
        rectBegin = 0,
        query = 1,
        rectEnd = 2
    } type;

    int x;

    union
    {
        int idx;
        int y1;
    };

    union
    {
        int y;
        int y2;
    };

    bool operator < (const Event& other) const
    {
        return x == other.x ? type < other.type : x < other.x;
    }
};

std::vector<Event> events;
std::set<int> ys;
std::unordered_map<int, int> permutation;

std::vector<int> answer;

constexpr int TREE_SIZE{1 << 20};

int tree[TREE_SIZE << 1];

void update(int l, int r, int val)
{
    l += TREE_SIZE - 1;
    r += TREE_SIZE + 1;

    while ((l >> 1) != (r >> 1))
    {
        if (not (l & 1))
        {
            tree[l + 1] += val;
        }

        if (r & 1)
        {
            tree[r - 1] += val;
        }

        l >>= 1;
        r >>= 1;
    }
}

int query(int pos)
{
    pos += TREE_SIZE;
    int result{0};

    while (pos)
    {
        result += tree[pos];
        pos >>= 1;
    }

    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, q;
    std::cin >> n >> q;

    answer = std::vector<int>(q);

    for (int i{0}; i < n; i++)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        events.push_back({.type = Event::rectBegin, .x = x1, .y1 = y1, .y2 = y2});
        events.push_back({.type = Event::rectEnd, .x = x2, .y1 = y1, .y2 = y2});

        ys.insert({y1, y2});
    }

    for (int i{0}; i < q; i++)
    {
        int x, y;
        std::cin >> x >> y;

        events.push_back({.type = Event::query, .x = x, .idx = i, .y = y});

        ys.insert(y);
    }

    std::sort(events.begin(), events.end());

    int count = 0;
    for (const auto y : ys)
    {
        permutation[y] = ++count;
    }

    for (const auto& e : events)
    {
        switch (e.type)
        {
            case Event::rectBegin:
            {
                update(permutation.at(e.y1), permutation.at(e.y2), 1);
                break;
            }
            case Event::query:
            {
                answer.at(e.idx) = query(permutation.at(e.y));
                break;
            }
            case Event::rectEnd:
            {
                update(permutation.at(e.y1), permutation.at(e.y2), -1);
                break;
            }
        }
    }

    for (const auto a : answer)
    {
        std::cout << a << '\n';
    }
}
