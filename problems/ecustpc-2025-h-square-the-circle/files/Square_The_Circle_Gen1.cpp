#include "testlib.h"
#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    setName("Generate the input of Square The Circle");
    int type = opt<int>("type");
    if (type == 0)
    {
        int seg = opt<int>("seg");
        vector<std::tuple<int, int, int>> tests;
        for (int t = 0; t <= 1; t++)
        {
            for (int i = 0; i <= 100; i++)
            {
                for (int j = 0; j <= 100; j++)
                {
                    if (i == 0 && j == 0)
                        continue;
                    tests.push_back({t, i, j});
                }
            }
        } 
        vector<std::tuple<int, int, int>> chosenTests;
        for (int i = seg * 1000; i < (seg + 1) * 1000 && i < (int)tests.size(); i++)
            chosenTests.push_back(tests[i]);
        cout << (int)chosenTests.size() << endl;
        for (auto [t, x, y] : chosenTests)
            cout << t << " " << x << " " << y << endl;
    }

    if (type == 1)
    {
        int testcases = opt<int>("testcases");
        cout << testcases << endl;
        for (int i = 0; i < testcases; i++)
        {
            int t = rnd.next(0, 1);
            int x = rnd.next(0, 100000);
            int y = rnd.next(0, 100000);
            while (x == 0 && y == 0)
            {
                x = rnd.next(0, 100000);
                y = rnd.next(0, 100000);
            }
            cout << t << " " << x << " " << y << endl;
        }
    }

    return 0;
}