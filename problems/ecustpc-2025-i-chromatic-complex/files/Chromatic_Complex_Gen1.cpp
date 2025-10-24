#include "testlib.h"
#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

struct data
{
    int n, m, c, k;
};

void generateData(data d)
{
    int n = d.n, m = d.m, c = d.c, k = d.k;
    cout << n << " " << m << " " << c << " " << k << "\n";

    vector<pair<int, int>> points(c + 1);
    std::set<pair<int, int>> used;
    for (int i = 0; i < c + 1; i++)
    {
        int x1 = rnd.next(0, n - 1);
        int y1 = rnd.next(0, m - 1);
        while (used.count({x1, y1}))
        {
            x1 = rnd.next(0, n - 1);
            y1 = rnd.next(0, m - 1);
        }
        used.insert({x1, y1});
        points[i] = {x1, y1};
    }
    cout << points[0].first + 1 << " " << points[0].second + 1 << "\n";
    std::vector<std::string> grid(n, std::string(m, '0'));
    for (int i = 0; i <= c; i++)
    {
        int r = rnd.next(0, 1);
        grid[points[i].first][points[i].second] = r + '1';
    }
    int lavarate = opt<int>("lr");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != '0')
            {
                grid[i][j] -= 1;
                continue;
            }
            int val = rnd.next(1, 100);
            if (val < lavarate)
                grid[i][j] = '2';
            else if (val < lavarate + (100 - lavarate) / 3)
                grid[i][j] = '1';
        }
    for (int i = 0; i < n; i++)
        cout << grid[i] << "\n";
    for (int i = 1; i <= c; i++)
    {
        cout << points[i].first + 1 << " " << points[i].second + 1 << "\n";
    }
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    setName("Generate the input of Chromatic Complex");

    int testcases = opt<int>("tc");
    int size = opt<int>("size");
    int lavarate = opt<int>("lr");
    vector<data> tests;
    if (size == 0)
    {
        for (int i = 0; i < testcases; i++)
        {
            int n = rnd.next(1, 20);
            int m = rnd.next(1, 20);
            while (n * m == 1)
            {
                n = rnd.next(1, 20);
                m = rnd.next(1, 20);
            }
            int c = std::max(std::min(rnd.next(1, 10), n * m - 1), 1);
            int k = rnd.next(1, c);
            tests.push_back({n, m, c, k});
        }
    }
    if (size == 1)
    {
        for (int i = 0; i < testcases; i++)
        {
            if (i < 5)
            {
                int n = rnd.next(600, 800);
                int m = rnd.next(600, 800);
                int c = 15;
                int k = rnd.next(1, c);
                tests.push_back({n, m, c, k});
            }
            else
            {
                int n = rnd.next(5, 90);
                int m = rnd.next(5, 90);
                int c = 10;
                int k = rnd.next(1, c);
                tests.push_back({n, m, c, k});
            }
        }
    }
    if (size == 2)
    {
        int n = 2000;
        int m = 2000;
        int c = 15;
        int k = 15;
        for (int i = 0; i < testcases; i++)
            tests.push_back({n, m, c, k});
    }
    cout << tests.size() << "\n";
    for (auto d : tests)
        generateData(d);
}
