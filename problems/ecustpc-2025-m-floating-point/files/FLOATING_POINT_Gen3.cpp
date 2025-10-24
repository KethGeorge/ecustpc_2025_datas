#include "testlib.h"
#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;



int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    registerGen(argc, argv, 1);
    setName("Generate 2^n + 1 testcases for FLOATING POINT");
    int n = (1 << opt<int>("n")) + 1;

    int totalSize = opt<int>("s");
    vector<int> S;
    int rest = totalSize, tc = 1'000;
    while (rest > n && tc > 0)
    {
        tc -= 1;
        int size = n;
        rest -= size;
        S.push_back(size);
    }
    if (rest > 0 && tc > 0)
        S.push_back(rest);
    shuffle(S.begin(), S.end());
    cout << S.size() << endl;
    for (auto i : S)
        cout << i << endl;
    return 0;
}