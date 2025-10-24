#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void solve()
{
    int n, kX, kY;
    cin >> n >> kX >> kY;

    vector<vector<int>> occupy(201, vector<int>(201, 0));
    vector<vector<int>> grid(201, vector<int>(201, 0));
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
        for (int st = 1; st <= 200; st++)
        {
            if (st != x)
                occupy[st][y] += 1;
            if (st != y)
                occupy[x][st] += 1;
        }
    }

    std::queue<pair<int, int>> q;
    q.push({kX, kY});

    const vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    vector<vector<int>> visited(201, vector<int>(201, 0));
    int eated = 0;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : directions)
        {
            int nx = x + dx, ny = y + dy;
            if (nx >= 1 && nx <= 200 && ny >= 1 && ny <= 200 && !occupy[nx][ny] && !visited[nx][ny])
            {
                if (grid[nx][ny] == 1)
                {
                    eated += 1;
                    if (eated == n)
                    {
                        cout << "YES" << endl;
                        return;
                    }
                    grid[nx][ny] = 0;
                    for (int st = 1; st <= 200; st++)
                    {
                        if (st != nx)
                            occupy[st][ny] -= 1;
                        if (st != ny)
                            occupy[nx][st] -= 1;
                    }
                    while (!q.empty())
                        q.pop();
                    q.push({nx, ny});
                    visited = vector<vector<int>>(201, vector<int>(201, 0));
                    visited[nx][ny] = 1;
                    break;
                }
                else
                {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << "NO" << endl;
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