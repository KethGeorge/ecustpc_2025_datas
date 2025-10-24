#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
#define endl "\n"
void Solve()
{
    int n, a1, d, m, k;
    cin >> n >> a1 >> d >> m >> k;
    if (d <= k)
    {
        cout << m + 1 << endl;
        return;
    }
    if (k == 0)
    {
        cout << m + n << endl;
        return;
    }

    int opsNeed = (d - 1) / k;
    int typesLoss = m / opsNeed;
    int newTypes = std::max<int>(1, n - typesLoss);
    cout << newTypes + m << endl;
    return;
}

int main()
{
    int testcases = 1;
    cin >> testcases;
    for (int i = 1; i <= testcases; i++)
        Solve();
}