#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    std::queue<pair<vector<int>, int>> q;
    q.push({vector<int>(n), 0});

    while (!q.empty())
    {
        auto [cur, dis] = q.front();
        q.pop();
        if (cur == a)
        {
            cout << dis << endl;
            return;
        }
        if (dis > n)
            break;

        for (int dir = 0; dir < 2; dir++)
        {
            for (int i = 0; i < n; i++)
            {
                auto newAns = cur;
                if (dir == 0) // left
                {
                    int cnt = 1;
                    for (int j = i; j >= 0; j--)
                    {
                        newAns[j] = cnt;
                        cnt += 1;
                    }
                }
                if (dir == 1) // right
                {
                    int cnt = 1;
                    for (int j = i; j < n; j++)
                    {
                        newAns[j] = cnt;
                        cnt += 1;
                    }
                }
                q.push({newAns, dis + 1});
            }
        }
    }

    cout << -1 << endl;

    return;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcases = 1;
    cin >> testcases;
    for (int i = 1; i <= testcases; i++)
        solve();
}