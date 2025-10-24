#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    setName("Generate the input of Fortress Fall, Random Data");
    int tc = opt<int>("tc");
    int n = opt<int>("n");
    int lA = opt<int>("lA");
    int rA = opt<int>("rA");
    int lX = opt<int>("lX");
    int rX = opt<int>("rX");
    int lY = opt<int>("lY");
    int rY = opt<int>("rY");
    cout << tc << endl;
    for (int t = 1; t <= tc; t++)
    {
        int x = rnd.next(lX, rX);
        int y = rnd.next(lY, rY);
        cout << n << " " << x << " " << y << endl;
        for (int i = 1; i <= n; i++)
        {
            int a = rnd.next(lA, rA);
            cout << a << (i == n ? '\n' : ' ');
        }
    }
}