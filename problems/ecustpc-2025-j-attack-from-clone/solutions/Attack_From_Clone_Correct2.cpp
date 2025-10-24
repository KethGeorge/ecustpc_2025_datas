#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void Solve()
{
    int n, a1, d, m, k;
    cin >> n >> a1 >> d >> m >> k;
    int needNum = 1'000'000;
    for (int insertNum = 0; insertNum <= d; insertNum++)
    {
        if (k * (insertNum + 1) >= d)
        {
            needNum = insertNum;
            break;
        }
    }
    int rest = m;
    int ans = n + m;
    for (int i = 1; i <= n - 1; i++)
    {
        if (rest >= needNum)
        {
            ans -= 1;
            rest -= needNum;
        }
    }
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
        Solve();
}