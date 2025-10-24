#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    setName("Check the answer of FLOATING POINT");
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int testCases = inf.readInt();
    int sumN = 0;
    for (int t = 1; t <= testCases; t++)
    {
        int n = inf.readInt();
        sumN += n;
        vector<int> Ans = ouf.readInts(n, -1, (1 << 30) - 1, "ans");
        if (std::ranges::min(Ans) == -1)
        {
            quitf(_wa, "There exists a legal answer for testcase %d, but the contestant reported no solution.", t);
        }
        for (int i = 0; i < n - 1; i++)
        {
            int andsum = Ans[i] & Ans[i + 1];
            int xorsum = Ans[i] ^ Ans[i + 1];
            if (!(Ans[i] < Ans[i + 1]))
            {
                quitf(_wa, "%d-th and %d-th number in the output of Testcase %d don't satisfy the condition of a_i < a_{i + 1}!", i + 1, i + 2, t);
            }
            if (!(xorsum < andsum))
            {
                quitf(_wa, "%d-th and %d-th number in the output of Testcase %d don't satisfy the condition of xorsum < andsum!", i + 1, i + 2, t);
            }
        }
    }


    int extraOut = 0;

    while (!ouf.seekEof())
    {
        ouf.readInt(0, (1 << 30) - 1, "ans");
        extraOut++;
    }


    if (extraOut > 0)
        quitf(_wa, "Output contains longer sequence [length = %d], but answer contains %d elements",
              sumN + extraOut, sumN);

    quitf(_ok, "%d testcases are correct.", testCases);

    return 0;
}