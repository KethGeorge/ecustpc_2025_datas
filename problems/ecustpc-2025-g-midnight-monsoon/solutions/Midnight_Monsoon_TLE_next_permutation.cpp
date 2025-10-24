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


    auto calc = [&](const vector<int> &a) -> LL
    {
        auto permutation = a;
        std::ranges::sort(permutation);
        LL ans = 1e18;
        do{
            LL cur = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 2; j < n; j++)
                {
                    cur += std::abs(permutation[i] - permutation[j]);
                }
            }
            ans = std::min(ans, cur);
        }while (std::next_permutation(permutation.begin(), permutation.end()));
        return ans;
    };

    for (int i = 1; i <= m; i++)
    {
        int id, delt;
        cin >> id >> delt;
        id -= 1;
        a[id] += delt;
        cout << calc(a) << endl;  
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