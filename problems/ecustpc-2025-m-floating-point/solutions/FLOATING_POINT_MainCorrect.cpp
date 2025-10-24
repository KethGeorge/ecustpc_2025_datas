#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
#define endl "\n"


void Solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << (1 << 25) + i << " ";
    }
    cout << endl;
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