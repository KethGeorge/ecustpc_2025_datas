#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
const int INF = 1'000'000'000;
int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    setName("Validate the input of Chromatic Complex");
    int testcases = inf.readInt(1, 100, "T");
    inf.readEoln();
    int totalNM = 0, totalC = 0;
    for (int t = 1; t <= testcases; t++)
    {
        int n = inf.readInt(1, 2000, "n");
        inf.readSpace();
        int m = inf.readInt(1, 2000, "m");
        inf.readSpace();
        int c = inf.readInt(1, 15, "c");
        inf.readSpace();
        int k = inf.readInt(1, c, "k");
        inf.readEoln();
        int sx = inf.readInt(1, n, "sx");
        inf.readSpace();
        int sy = inf.readInt(1, m, "sy");
        inf.readEoln();

        totalNM += n * m;
        if (c > 10)
            totalC += 1;
        vector<std::string> grid(n);
        for (int i = 0; i < n; i++)
        {
            grid[i] = inf.readLine("[0-2]{1,2000}", "gridLine");
            if ((int)grid[i].size() != m)
                quitf(_fail, "The length of %d-th line is not equal to m", i + 1);
        }
        std::map<pair<int, int>, int> gems;
        for (int i = 0; i < c; i++)
        {
            int x = inf.readInt(1, n, "colorX");
            inf.readSpace();
            int y = inf.readInt(1, m, "colorY");
            inf.readEoln();
            if (grid[x - 1][y - 1] == '2')
                quitf(_fail, "The position of gem %d is on the lava", i + 1);
            gems[{x, y}] += 1;
            if (gems[{x, y}] >= 2)
                quitf(_fail, "There are at least two gems on the same position");
        }
        if (grid[sx - 1][sy - 1] == '2')
            quitf(_fail, "The starting position is on the lava");
        if (gems.find({sx, sy}) != gems.end())
            quitf(_fail, "There is a gem on the starting position");
    }
    ensuref(totalNM <= 4'000'000, "Sum of n*m should not exceed 4000000");
    ensuref(totalC <= 5, "There are more than 5 test cases with c > 10");
    inf.readEof();
}
