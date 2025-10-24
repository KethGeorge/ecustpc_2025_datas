#include "testlib.h"
#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;


int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    setName("Generate the input of Tower XVI");

    int testcases = opt<int>("tc");
    int size = opt<int>("size");
    cout << testcases << "\n";
    for (int i = 1; i <= testcases; i++)
    {
        int n = 0, m = 0;
        if (size == -1)
        {
            n = rnd.next(1, 1000);
            m = rnd.next(1, 10);
            cout << n << " " << m << "\n";
            continue;
        }
        if (size == 0)
        {
            n = rnd.next(1, 1000);
            m = rnd.next(1, 1000);
            cout << n << " " << m << "\n";
            continue;
        }
        if (size == 1)
        {
            n = rnd.next(1, 1'000'000'000);
            m = rnd.next(1, 1'000'000'000);
            cout << n << " " << m << "\n";
        }
        if (size == 2)
        {
            n = rnd.next(999'999'900, 1'000'000'000);
            m = rnd.next(999'999'900, 1'000'000'000);
            cout << n << " " << m << "\n";
        }
    }
}