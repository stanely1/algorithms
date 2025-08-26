#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5 + 3;

// in this case when edge x -> y is added, also edge y -> x is added - we have undirected graph
vector<int> graph[MAXN];
int connected_component[MAXN];

inline int vertex_id(int x)
{
    return x << 1;
}

inline int vertex_neg_id(int x)
{
    return (x << 1) | 1;
}

void add_clause(int x, int y, bool unlocked)
{
    if (unlocked)
    {
        graph[vertex_id(x)].push_back(vertex_id(y));
        graph[vertex_id(y)].push_back(vertex_id(x));
        graph[vertex_neg_id(x)].push_back(vertex_neg_id(y));
        graph[vertex_neg_id(y)].push_back(vertex_neg_id(x));
    }
    else
    {
        graph[vertex_id(x)].push_back(vertex_neg_id(y));
        graph[vertex_neg_id(y)].push_back(vertex_id(x));
        graph[vertex_id(y)].push_back(vertex_neg_id(x));
        graph[vertex_neg_id(x)].push_back(vertex_id(y));
    }
}

void dfs(int x, int cc)
{
    connected_component[x] = cc;
    for (auto y : graph[x])
    {
        if (connected_component[y] == 0)
        {
            dfs(y, cc);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<bool> door_state(n+1);
    vector<pair<int, int>> door_switches(n+1, {0, 0});

    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        door_state[i] = static_cast<bool>(x);
    }

    for (int i = 1; i <= m; i++)
    {
        int x; cin >> x;
        while (x --> 0)
        {
            int y; cin >> y;
            if (door_switches[y].first == 0)
            {
                door_switches[y].first = i;
            }
            else
            {
                door_switches[y].second = i;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        const auto& [x, y] = door_switches[i];
        add_clause(x, y, door_state[i]);
    }

    for (int i = 1; i <= m; i++)
    {
        int v_id = vertex_id(i);
        if (connected_component[v_id] == 0)
        {
            dfs(v_id, v_id);
        }

        int neg_id = vertex_neg_id(i);
        if (connected_component[neg_id] == connected_component[v_id])
        {
            return cout << "NO\n", 0;
        }
        else if (connected_component[neg_id] == 0)
        {
            dfs(neg_id, neg_id);
        }
    }

    cout << "YES\n";
}
