#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<LL> dist(n, 0);
    vector<LL> sz(n, 1);

    auto dfs1 = [&](auto self, int u, int fa, int dep) -> LL
    {
        dist[0] += dep;
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            sz[u] += self(self, v, u, dep + 1);
        }
        return sz[u];
    };

    auto dfs2 = [&](auto self, int u, int fa) -> void
    {
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            dist[v] = dist[u] + (sz[0] - sz[v]) - sz[v];
            self(self, v, u);
        }
    };

    dfs1(dfs1, 0, -1, 0);
    dfs2(dfs2, 0, -1);

    vector<LL> a(n);

    for (auto &i : a)
        cin >> i;
    vector<LL> delt(n);

    for (int i = 0; i < n; i++)
        delt[i] = dist[i] - a[i];
    vector<char> diff(n);
    auto dfs3 = [&](auto self, int u, int fa) -> void
    {
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            if (delt[u] != delt[v])
            {
                diff[u] += 1;
                diff[v] += 1;
            }
            self(self, v, u);
        }
    };
    dfs3(dfs3, 0, -1);
    vector<int> dist1(n, -1);
    auto dfs4 = [&](auto self, int u, int fa, int d) -> void
    {
        dist1[u] = d;
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            self(self, v, u, d + 1);
        }
    };
    int v1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (diff[i] == 1)
        {
            v1 = i;
            break;
        }
    }
    dfs4(dfs4, v1, -1, 0);
    int x = v1;
    for (int i = 0; i < n; i++)
    {
        if (diff[i] == 1)
        {
            if (dist1[x] < dist1[i])
                x = i;
        }
    }

    dfs4(dfs4, x, -1, 0);
    int y = x;
    for (int i = 0; i < n; i++)
    {
        if (diff[i] == 1)
        {
            if (dist1[y] < dist1[i])
                y = i;
        }
    }
    cout << x + 1 << " " << y + 1 << endl;
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