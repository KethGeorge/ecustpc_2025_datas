#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void Solve()
{
    int n;
    cin >> n;
    vector<int> A(n);

    A[0] = (1 << 22);
    for (int i = 1; i < n; i++)
    {
        for (int j = (1 << 23) - 1; j > A[i - 1]; j--)
        {
            if ((j ^ A[i - 1]) < (j & A[i - 1]))
                A[i] = j;
        }
    }
    for (auto i : A)
        cout << i << " ";
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