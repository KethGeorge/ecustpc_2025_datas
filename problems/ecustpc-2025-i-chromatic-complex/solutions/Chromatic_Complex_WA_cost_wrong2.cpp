#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void solve()
{
    int n, m, c, k;
    cin >> n >> m >> c >> k;
    int sx, sy;
    cin >> sx >> sy;
    sx -= 1;
    sy -= 1;
    vector<std::string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<pair<int, int>> gems(c);
    for (int i = 0; i < c; i++)
    {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        gems[i] = {x, y};
    }
    const vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    auto bfs = [&](int st) -> vector<int>
    {
        std::deque<pair<int, int>> dq;
        int stX = (st == 0 ? sx : gems[st - 1].first);
        int stY = (st == 0 ? sy : gems[st - 1].second);
        vector<vector<int>> dis(n, vector<int>(m, -1));
        dis[stX][stY] = 0;
        dq.push_back({stX, stY});
        const vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!dq.empty())
        {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (auto [dx, dy] : dir)
            {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (grid[nx][ny] == '2')
                    continue;
                // 错误：按“出发格是否为水”收费
                int w = (grid[x][y] == '1') ? 1 : 0;
                if (dis[nx][ny] == -1 || dis[nx][ny] > dis[x][y] + w)
                {
                    dis[nx][ny] = dis[x][y] + w;
                    if (w == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }
        vector<int> res(c + 1, -1);
        res[0] = dis[sx][sy];
        for (int i = 1; i <= c; i++)
            res[i] = dis[gems[i - 1].first][gems[i - 1].second];
        return res;
    };
    vector<vector<int>> dist(c + 1, vector<int>(c + 1, -1));
    for (int i = 0; i <= c; i++)
        dist[i] = bfs(i);

    int ans = 1'000'000'000;

    vector<vector<int>> dp(1 << c, vector<int>(c, -1));
    for (int i = 0; i < c; i++)
    {
        if (dist[0][i + 1] != -1)
            dp[1 << i][i] = dist[0][i + 1];
    }

    for (int mask = 0; mask < (1 << c); mask++)
    {
        for (int u = 0; u < c; u++)
        {
            if ((mask >> u) & 1)
            {
                if (dp[mask][u] == -1)
                    continue;
                for (int v = 0; v < c; v++)
                {
                    if (!((mask >> v) & 1) && dist[u + 1][v + 1] != -1)
                    {
                        int nmask = mask | (1 << v);
                        int ndist = dp[mask][u] + dist[u + 1][v + 1];
                        if (dp[nmask][v] == -1 || dp[nmask][v] > ndist)
                            dp[nmask][v] = ndist;
                    }
                }
            }
        }
    }
    for (int mask = 0; mask < (1 << c); mask++)
    {
        if (__builtin_popcount(mask) >= k)
        {
            for (int u = 0; u < c; u++)
            {
                if ((mask >> u) & 1 && dp[mask][u] != -1)
                {
                    ans = std::min(ans, dp[mask][u]);
                }
            }
        }
    }
    if (ans == 1'000'000'000)
        ans = -1;
    cout << ans << endl;
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