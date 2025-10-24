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
    setName("Generate random testcases for FLOATING POINT");
    int nL = opt<int>("l");
    int nR = opt<int>("r");
    int totalSize = opt<int>("s");
    vector<int> S;
    int rest = totalSize, tc = 1'000;
    while (rest > nL && tc > 0)
    {
        tc -= 1;
        int rndSize = rnd.next(nL, std::min<int>(nR, rest));
        rest -= rndSize;
        S.push_back(rndSize);
    }
    if (rest > 0 && tc > 0)
        S.push_back(rest);
    shuffle(S.begin(), S.end());
    cout << S.size() << endl;
    for (auto i : S)
        cout << i << endl;
    return 0;
}