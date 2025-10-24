#include "testlib.h"
#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;



int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    registerGen(argc, argv, 1);
    setName("Generate sequential testcases for FLOATING POINT");

    int tc = opt<int>("tc");
    cout << tc << endl;
    for (int i = 2; i <= tc + 1; i++)
    {
        cout << i << endl;
    }
    return 0;
}