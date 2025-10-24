#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void Solve()
{
    int a, b;
    cin >> a >> b;
    auto Output = [&](int a, int b) -> bool
    {
        if (a >= 24 || b >= 60)
            return false;
        cout << std::format("{}{}:{}{}", a / 10, a % 10, b / 10, b % 10) << endl;
        return true;
    };
    auto Check = [&](int h, int m) -> bool
    {
        if ((h == a && m == b) && Output(h, m))
        {
            return true;
        }
        if ((h == b && m == a) && Output(h, m))
        {
            return true;
        }
        return false;
    };

    for (int h = 0; h < 24; h++)
    {
        for (int m = 0; m < 60; m++)
        {
            if (Check(h, m))
                return;
        }
    }
    cout << "-1" << endl;
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