#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // coef1: a_1 >= a_2 <= a_3 >= a_4 <= a_5 ...
    // coef2: a_1 <= a_2 >= a_3 <= a_4 >= a_5 ...
    vector<int> coef1(n), coef2(n);

    for (int i = 0; i < n - 1; i++)
    {
        if (i % 2 == 0)
        {
            coef1[i] += 1;
            coef1[i + 1] -= 1;
        }
        else
        {
            coef1[i] -= 1;
            coef1[i + 1] += 1;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (i % 2 == 0)
        {
            coef2[i] -= 1;
            coef2[i + 1] += 1;
        }
        else
        {
            coef2[i] += 1;
            coef2[i + 1] -= 1;
        }
    }
    std::ranges::sort(coef1);
    std::ranges::sort(coef2);
    int curCoef = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        coef1[i] *= -1;
        coef1[i] += curCoef;
        coef2[i] *= -1;
        coef2[i] += curCoef;
        curCoef -= 2;
    }
    auto sorted = a;
    std::ranges::sort(sorted);

    LL ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        ans1 += (LL)sorted[i] * coef1[i];
        ans2 += (LL)sorted[i] * coef2[i];
    }

    for (int i = 1; i <= m; i++)
    {
        int id = 0, delt = 0;
        cin >> id >> delt;
        id -= 1;
        bool minus = false;
        if (delt < 0)
        {
            delt *= -1;
            minus = true;
        }
        int curA = a[id];
        for (int j = 1; j <= delt; j++)
        {
            if (!minus)
            {
                auto i = std::upper_bound(sorted.begin(), sorted.end(), curA);
                int pos = i - sorted.begin() - 1;
                sorted[pos] += 1;
                ans1 += coef1[pos];
                ans2 += coef2[pos];
                curA += 1;
            }
            else
            {
                auto i = std::lower_bound(sorted.begin(), sorted.end(), curA);
                int pos = i - sorted.begin();
                sorted[pos] -= 1;
                ans1 -= coef1[pos];
                ans2 -= coef2[pos];
                curA -= 1;
            }
        }
        a[id] = curA;
        cout << ans2 << endl;
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
        solve();
}