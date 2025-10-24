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
    int nL = opt<int>("n");
    int dL = opt<int>("d");
    int mL = opt<int>("m");
    int kL = opt<int>("k");
    cout << tc << endl;
    for (int i = 1; i <= tc; i++)
    {
        int n = rnd.next(nL, 100);
        int a = rnd.next(95, 100);
        int k = rnd.next(kL, 100);
        int d = rnd.next(dL, 100);
        int m = rnd.next(mL, 100);
        cout << std::format("{} {} {} {} {}", n, a, d, m, k) << endl;
    }
    return 0;
}