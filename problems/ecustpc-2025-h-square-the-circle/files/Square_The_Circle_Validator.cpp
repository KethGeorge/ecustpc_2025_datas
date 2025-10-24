#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    setName("Validate the input of Square The Circle");
    int testcases = inf.readInt(1, 1'000, "testcases");
    inf.readEoln();
    for (int i = 1; i <= testcases; i++)
    {
        int type = inf.readInt(0, 1, "type");
        inf.readSpace();
        int x = inf.readInt(0, 100'000, "x");
        inf.readSpace();
        int y = inf.readInt(0, 100'000, "y");
        inf.readEoln();
        ensuref(x != 0 || y != 0, "Both x and y are zero on testcase %d!", i);
    }

    inf.readEof();
}
