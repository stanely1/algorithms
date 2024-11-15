#include <bits/stdc++.h>
using namespace std;

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

        if ((n & 1) == 0)
        {
            for (int i = 1; i <= (n >> 1); i++)
            {
                cout << i << ' ' << i << ' ';
            }
        }
        else if (n >= 27)
        {
            for (int _ = 0; _ < 2; _++)
            {
                cout << "2 1 ";
                for (int i = 3; i <= 9; i++)
                {
                    cout << i << ' ';
                }
            }
            for (int i = 10; i <= 13; i++)
            {
                cout << i << ' ' << i << ' ';
            }
            cout << "1 ";
            for (int i = 14; i <= (n >> 1); i++)
            {
                cout << i << ' ' << i << ' ';
            }
        }
        else
        {
            cout << "-1";
        }
        cout << '\n';
    }
}
