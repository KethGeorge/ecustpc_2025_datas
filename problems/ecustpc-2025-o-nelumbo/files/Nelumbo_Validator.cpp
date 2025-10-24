#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
const int INF = 1'000'000'000;
int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    setName("Validate the input of Nelumbo");

    auto findf = [&](auto self, vector<int> &fa, int x) -> int
    {
        if (fa[x] != x)
            fa[x] = self(self, fa, fa[x]);
        return fa[x];
    };

    auto Merge = [&](vector<int> &fa, int x, int y)
    {
        int fx = findf(findf, fa, x);
        int fy = findf(findf, fa, y);
        if (fx != fy)
            fa[fx] = fy;
    };

    int testcases = inf.readInt(1, 100'000, "T");
    inf.readEoln();
    int totalN = 0;
    for (int t = 1; t <= testcases; t++)
    {
        int n = inf.readInt(2, 100'000, "n");
        inf.readEoln();
        vector<int> fa(n + 1);
        for (int i = 1; i <= n; i++)
            fa[i] = i;

        for (int i = 1; i < n; i++)
        {
            int x = inf.readInt(1, n, "x");
            inf.readSpace();
            int y = inf.readInt(1, n, "y");
            inf.readEoln();
            if (x == y)
                quitf(_fail, "There is a self-loop in the graph");
            Merge(fa, x, y);
        }

        int root = findf(findf, fa, 1);
        for (int i = 2; i <= n; i++)
        {
            if (findf(findf, fa, i) != root)
                quitf(_fail, "The graph is not connected");
        }
        totalN += n;
        for (int i = 1; i <= n; i++)
        {
            inf.readInt(1, n, "a_i");
            if (i < n)
                inf.readSpace();
            else
                inf.readEoln();
        }
    }
    ensuref(totalN <= 300'000, "Sum of n should not exceed 300000");
    inf.readEof();
}
