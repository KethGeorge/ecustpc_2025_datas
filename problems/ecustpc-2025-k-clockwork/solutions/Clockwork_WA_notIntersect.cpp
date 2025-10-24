
#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void solve()
{
    const int INF = 1'000'000'000;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    a.insert(a.begin(), 0);
    a.insert(a.end(), 0);
    vector<int> f(n + 2), g(n + 2);

    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || a[i - 1] == 1)
            f[i] = f[i - 1] + 1;
        else
        {
            if (a[i] == a[i - 1] - 1)
                f[i] = f[i - 1];
            else
                f[i] = INF;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (i == n || a[i + 1] == 1)
            g[i] = g[i + 1] + 1;
        else
        {
            if (a[i] == a[i + 1] - 1)
                g[i] = g[i + 1];
            else
                g[i] = INF;
        }
    }

    int ans = 2 * INF;
    ans = std::min(f[n], g[1]);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1 && a[i + 1] == 1)
        {
            ans = std::min(ans, f[i] + g[i + 1]);
        }
    }

    if (ans > 2 * n)
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