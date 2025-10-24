#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    setName("Validate the input of Fortress Fall");
    int testcases = inf.readInt(1, 100'000, "T");
    inf.readEoln();
    int totalN = 0;
    for (int t = 1; t <= testcases; t++)
    {
        int n = inf.readInt(2, 100'000, "n");
        inf.readSpace();
        inf.readInt(-1'000'000, 1'000'000, "x");
        inf.readSpace();
        inf.readInt(-1'000'000, 1'000'000, "y");
        inf.readEoln();
        for (int i = 1; i <= n; i++)
        {
            inf.readInt(-1'000'000, 1'000'000, "a_i");
            if (i == n)
                inf.readEoln();
            else
                inf.readSpace();
        }
        totalN += n;
    }
    ensuref(totalN <= 300'000, "Sum of n should not exceed 300000");
    inf.readEof();
}
