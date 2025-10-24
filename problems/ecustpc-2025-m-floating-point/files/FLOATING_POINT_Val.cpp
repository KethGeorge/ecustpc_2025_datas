#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    setName("Validate the input of FLOATING POINT");

    int n = inf.readInt(1, 1000, "tc");
    inf.readEoln();
    int sumN = 0;
    for (int i = 1; i <= n; i++)
    {
        int n = inf.readInt(2, 1'000'000, "n");
        sumN += n;
        inf.readEoln();
    }
    ensuref(sumN <= 1'000'000, "The sum of N is too big!");
    inf.readEof();
}