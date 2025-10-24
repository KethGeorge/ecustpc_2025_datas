#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    setName("Validate the input of Attack From Clone");

    int n = inf.readInt(1, 100, "tc");
    inf.readEoln();
    for (int i = 1; i <= n; i++)
    {
        inf.readInt(1, 100, "n");
        inf.readSpace();
        inf.readInt(1, 100, "a1");
        inf.readSpace();
        inf.readInt(0, 100, "d");
        inf.readSpace();
        inf.readInt(1, 100, "m");
        inf.readSpace();
        inf.readInt(0, 100, "k");
        inf.readEoln();
    }
    inf.readEof();
}