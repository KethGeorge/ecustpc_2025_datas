#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    setName("Generate the input of Time Trouble");

    int n = opt<int>("n");
    cout << n << endl;
    for (int i = 1; i <= n; i++)
    {
        int a = rnd.next(0, 99);
        int b = rnd.next(0, 99);
        cout << a << " " << b << endl;
    }
}