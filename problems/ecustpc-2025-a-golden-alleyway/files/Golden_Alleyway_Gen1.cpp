#include "testlib.h"
#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    setName("Generate the input of Goldenway Alleyway");
    int n = rnd.next(1, 3);

    int g = rnd.next(0, 7);
    int s = rnd.next(0, 7);
    int b = rnd.next(0, 7);
    while (g + s + b > 7)
    {
        g = rnd.next(0, 7);
        s = rnd.next(0, 7);
        b = rnd.next(0, 7);
    }
    cout << n << " " << g << " " << s << " " << b << endl;
}