#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    setName("Validate the input of Goldenway Alleyway");

    int n = inf.readInt(1, 3, "n");
    inf.readSpace();
    int g = inf.readInt(0, 7, "g");
    inf.readSpace();
    int s = inf.readInt(0, 7, "s");
    inf.readSpace();
    int b = inf.readInt(0, 7, "b");
    inf.readEoln();
    inf.readEof();
    ensuref(g + s + b <= 7, "the team attended too many contests");
}

