#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void Solve()
{
    int n, a1, d, m, k;
    cin >> n >> a1 >> d >> m >> k;

    vector<char> Filled(10'200);
    int an = a1;
    for (int i = 0; i < n; i++)
    {
        Filled[an] = 1;
        an += d;
    }

    auto Calc = [&]() -> int
    {
        std::set<int> A;
        for (int i = a1; i <= an; i++)
        {
            if (Filled[i])
                A.insert(i);
        }
        int cnt = 0;
        int last = -1'000'000'000;
        for (auto i : A)
        {
            if (i - last > k)
                cnt += 1;
            last = i;
        }
        if (cnt == 1)
            cout << "";
        return cnt;
    };
    int minAns = 1'000'000'000;
    auto Dfs = [&](auto self, int at, int last) -> void
    {
        minAns = std::min<int>(minAns, Calc());
        if (at == m)
        {
            return;
        }
        for (int i = last; i <= an; i++)
        {
            Filled[i] += 1;
            self(self, at + 1, i);
            Filled[i] -= 1;
        }
    };

    Dfs(Dfs, 0, a1);
    cout << minAns + m << endl;

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