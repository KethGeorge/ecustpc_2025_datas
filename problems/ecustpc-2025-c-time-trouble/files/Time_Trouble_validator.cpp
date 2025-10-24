#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    setName("Validate the input of Time Trouble");

    int n = inf.readInt(1, 10000, "n");
    inf.readEoln();
    for (int i = 1; i <= n; i++)
    {
        inf.readInt(0, 99, "a");
        inf.readSpace();
        inf.readInt(0, 99, "b");
        inf.readEoln();
    }
    inf.readEof();
}