#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void Solve()
{
    auto Output = [&](int a, int b) -> bool
    {
        if (a >= 24 || b >= 60)
            return false;
        cout << std::format("{}{}:{}{}", a / 10, a % 10, b / 10, b % 10) << endl;
        return true;
    };
    int a, b;
    cin >> a >> b;
    if (Output(a, b))
        return;
    if (Output(b, a))
        return;
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