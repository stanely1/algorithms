#include <bits/stdc++.h>
using namespace std;

deque<bool> result;

string result_str()
{
    string res = "";
    for (auto x : result)
    {
        res += x ? '1' : '0';
    }
    return res;
}

void query()
{
    cout << "? " << result_str() << '\n';
    cout.flush();
}

void answer()
{
    cout << "! " << result_str() << '\n';
    cout.flush();
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
        int n;
        cin >> n;

        bool is_suffix = false;
        bool x;

        int query_count = 0;

        while (not is_suffix and result.size() < n)
        {
            result.push_back(0);

            query_count++;
            query();

            cin >> x;
            if (not x)
            {
                result.back() = 1;

                query_count++;
                query();

                cin >> x;
                if (not x)
                {
                    result.pop_back();
                    is_suffix = true;
                    break;
                }
            }
        }

        while (query_count < 2 * n and result.size() < n)
        {
            result.push_front(0);
            query_count++;
            query();

            cin >> x;
            if (not x)
            {
                result.front() = 1;
            }
        }

        answer();

        result.clear();
    }
}
