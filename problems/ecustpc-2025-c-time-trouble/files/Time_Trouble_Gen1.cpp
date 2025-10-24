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
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << a << " " << b << endl;
        b += 1;
        if (b >= 100)
        {
            b = 0;
            a += 1;
        }
    }
}