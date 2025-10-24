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
    setName("Generate random testcases which satisfy d <= k for Hypnagogla");
    int tc = opt<int>("tc");
    int nR = opt<int>("n");
    int dR = opt<int>("d");
    int mR = opt<int>("m");
    int kR = opt<int>("k");
    cout << tc << endl;
    for (int i = 1; i <= tc; i++)
    {
        int n = rnd.next(1, nR);
        int a = rnd.next(1, 100);
        int k = rnd.next(0, kR);
        int d = rnd.next(0, std::min<int>(k, dR));
        int m = rnd.next(1, mR);
        cout << std::format("{} {} {} {} {}", n, a, d, m, k) << endl;
    }
    return 0;
}