#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int l, m2, m3;
    cin >> l >> m2 >> m3;

    for (int i = l; i < l + 6; i++)
    {
        if (i % 2 == m2 && i % 3 == m3)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}