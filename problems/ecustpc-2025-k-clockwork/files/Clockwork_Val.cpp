#include "testlib.h"
#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    setName("Validate the input of Clockwork");
    int tc = inf.readInt(1, 100'000, "tc");
    int totalN = 0;
    inf.readEoln();
    for (int i = 1; i <= tc; i++)
    {
        int n = inf.readInt(1, 100'000, "n");
        totalN += n;
        inf.readEoln();
        for (int j = 1; j <= n; j++)
        {
            int a_i = inf.readInt(1, n, "a_i");
            if (j < n)
                inf.readSpace();
            else
                inf.readEoln();
        }
    }
    ensuref(totalN <= 300'000, "Sum of n should be at most 300000");
    inf.readEof();
}