#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
const int INF = 1'000'000'000;
int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    setName("Validate the input of In Filtration");
    int testcases = inf.readInt(1, 100'000, "T");
    inf.readEoln();
    int totalN = 0;
    for (int t = 1; t <= testcases; t++)
    {
        int n = inf.readInt(1, 100'000, "n");
        inf.readEoln();
        int X = inf.readInt(1, INF, "x");
        inf.readSpace();
        int Y = inf.readInt(1, INF, "y");
        inf.readEoln();
        std::map<pair<int, int>, int> tokens;
        for (int i = 1; i <= n; i++)
        {
            int x1 = inf.readInt(1, INF, "x1");
            inf.readSpace();
            int y1 = inf.readInt(1, INF, "y1");
            inf.readEoln();
            tokens[{x1, y1}] += 1;
            if (tokens[{x1, y1}] >= 2)
            {
                quitf(_fail, "There are at least two identical points");
            }
            if (x1 == X || y1 == Y)
            {
                quitf(_fail, "There is a black rook attacking the white king");
            }
        }
        totalN += n;
    }
    ensuref(totalN <= 300'000, "Sum of n should not exceed 300000");
    inf.readEof();
}
