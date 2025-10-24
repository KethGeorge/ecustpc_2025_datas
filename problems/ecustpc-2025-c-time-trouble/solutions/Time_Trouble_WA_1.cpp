#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
#define endl "\n"

void Solve()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
        std::swap(a, b);
    if (a >= 24 || b >= 60)
    {
        cout << "-1" << endl;
        return;
    }

    if (a < 10)
        cout << '0';
    cout << a << ':' << b << endl;
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