#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void Solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<LL> a(n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (auto &i : a)
        cin >> i;
    auto bfs = [&](const vector<vector<int>> &g, int start) -> vector<int>
    {
        int n = g.size();
        vector<int> dist(n, -1);
        std::queue<int> q;
        q.push(start);
        dist[start] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : g[u])
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    };

    auto bruteForce = [&](int x, int y) -> vector<LL>
    {
        auto g2 = g;
        g2[x].push_back(y);
        g2[y].push_back(x);
        vector<LL> dist(n, 0);
        for (int i = 0; i < n; i++)
        {
            auto d = bfs(g2, i);
            for (int j = 0; j < n; j++)
                dist[i] += d[j];
        }
        return dist;
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            auto dist = bruteForce(i, j);
            bool ok = true;
            for (int k = 0; k < n; k++)
            {
                if (dist[k] - a[k] != 0)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
    }

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
        Solve();
}