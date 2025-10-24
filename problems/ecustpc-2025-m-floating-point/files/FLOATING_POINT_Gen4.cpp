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
    setName("Generate Single testcases for FLOATING POINT");
    int n = opt<int>("n");
    cout << 1 << endl << n << endl;
    return 0;
}