#include "testlib.h"
#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    setName("Generate the input of Seeing is Believing");
    int l = rnd.next(0, 100);
    int m2 = rnd.next(0, 1);
    int m3 = rnd.next(0, 2);
    cout << l << ' ' << m2 << ' ' << m3 << endl;
}