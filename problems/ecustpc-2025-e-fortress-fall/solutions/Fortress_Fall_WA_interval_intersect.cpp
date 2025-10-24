#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
const LL INF = 1e18;
void solve()
{
    int n;
    int x, y;
    cin >> n >> x >> y;
    if (x < y)
        std::swap(x, y);
    vector<LL> a(n);

    for (auto &i : a)
        cin >> i;

    std::ranges::sort(a);

    vector<int> pref(n);
    std::partial_sum(a.begin(), a.end(), pref.begin());

    auto getIntervalSum = [&](int l, int r) -> LL
    {
        if (l > r)
            return 0;
        return pref[r] - (l == 0 ? 0 : pref[l - 1]);
    };

    auto getSum = [&](int pickNum) -> LL
    {
        if (pickNum * 2 > n)
            return -INF;
        if (y >= 0)
        {
            return x * getIntervalSum(n - pickNum, n - 1) + y * getIntervalSum(n - pickNum * 2, n - pickNum - 1);
        }
        if (x >= 0)
        {
            return x * getIntervalSum(n - pickNum, n - 1) + y * getIntervalSum(0, pickNum - 1);
        }
        if (x < 0)
        {
            return y * getIntervalSum(0, pickNum - 1) + x * getIntervalSum(pickNum, 2 * pickNum - 1);
        }
        return -INF;
    };

    LL ans = 0;
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        ans = std::max(ans, getSum(i));
    }
    cout << ans << endl;
    return;
}

int main()
{
    int testcases = 1;
    cin >> testcases;
    for (int i = 1; i <= testcases; i++)
        solve();
}