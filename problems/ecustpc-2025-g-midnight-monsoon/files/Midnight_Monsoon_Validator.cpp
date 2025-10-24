#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    setName("Validate the input of Midnight Monsoon");
    int testcases = inf.readInt(1, 100'000, "T");
    inf.readEoln();
    int totalN = 0;
    int totalM = 0;
    int totalDelt = 0;
    const int contraintOnA = 100'000'000;
    for (int i = 1; i <= testcases; i++)
    {
        int n = inf.readInt(2, 100'000, "n");
        inf.readSpace();
        int m = inf.readInt(1, 100'000, "m");
        inf.readEoln();
        for (int j = 1; j <= n; j++)
        {
            inf.readInt(-contraintOnA, contraintOnA, "a_i");
            if (j < n)
                inf.readSpace();
            else
                inf.readEoln();
        }
        int curDelt = 0;
        for (int j = 1; j <= m; j++)
        {
            int id = inf.readInt(1, n, "x");
            inf.readSpace();
            int delt = inf.readInt(-100'000'000, 100'000'000, "y");
            inf.readEoln();
            curDelt += (delt < 0 ? -delt : delt);
        }
        ensuref(curDelt <= 100'000'000, "Total |delt| in one testcase must be at most 100000000");
    }
    inf.readEof();
    ensuref(totalN <= 300'000, "Total n over all test cases must be at most 300000");
    ensuref(totalM <= 300'000, "Total m over all test cases must be at most 300000");

}

