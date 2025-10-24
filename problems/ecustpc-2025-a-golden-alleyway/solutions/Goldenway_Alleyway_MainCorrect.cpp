#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, g, s, b;
    cin >> n >> g >> s >> b;
    cout << (7500 * g + 3000 * s + 1500 * b) / n << endl;

    return 0;
}