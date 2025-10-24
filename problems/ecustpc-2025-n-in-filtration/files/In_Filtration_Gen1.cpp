#include "testlib.h"
#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
vector<LL> generateSequence(int n, LL l, LL r, LL total_sum)
{
    LL min_sum = l * 1LL * n;
    LL max_sum = r * 1LL * n;
    if (total_sum < min_sum || total_sum > max_sum)
    {
        quitf(_fail, "No solution: total_sum out of range [%lld, %lld]", min_sum, max_sum);
    }

    vector<LL> a(n);
    LL remain = total_sum;

    for (int i = 0; i < n; ++i)
    {
        int left = n - i - 1;

        LL low_i = std::max(l, remain - r * 1LL * left);
        LL up_i = std::min(r, remain - l * 1LL * left);

        a[i] = rnd.next(low_i, up_i);
        remain -= a[i];
    }
    shuffle(a.begin(), a.end());
    return a;
}

struct Data
{
    int n;
    LL x, y;
    std::vector<std::pair<LL, LL>> points;
};

void outputData(const Data &data)
{
    cout << data.n << endl
         << data.x << " " << data.y << endl;
    for (auto [x, y] : data.points)
    {
        cout << x << " " << y << endl;
    }
}
Data generateOK(int n, LL rangeL, LL rangeR)
{
    // Guarantee that n << range.
    Data data;
    data.n = n;
    vector<int> x(1, 0), y(1, 0);
    int lX = -1, rX = 1, lY = -1, rY = 1;
    for (int i = 1; i <= n; i++)
    {
        int chk = rnd.next(0, 3);
        if (chk == 0)
        {
            x.push_back(lX);
            lX -= 1;
            y.push_back(lY);
            lY -= 1;
        }
        if (chk == 1)
        {
            x.push_back(rX);
            rX += 1;
            y.push_back(lY);
            lY -= 1;
        }
        if (chk == 2)
        {
            x.push_back(lX);
            lX -= 1;
            y.push_back(rY);
            rY += 1;
        }
        if (chk == 3)
        {
            x.push_back(rX);
            rX += 1;
            y.push_back(rY);
            rY += 1;
        }
    }
    vector<int> discX(2 * n + 1), discY(2 * n + 1);
    std::map<int, int> exiX, exiY;
    for (int i = 0; i <= 2 * n; i++)
    {
        int tx = rnd.next(rangeL, rangeR);
        while (exiX[tx] == 1)
        {
            tx = rnd.next(rangeL, rangeR);
        }
        discX[i] = tx;
        exiX[tx] = 1;
        int ty = rnd.next(rangeL, rangeR);
        while (exiY[ty] == 1)
        {
            ty = rnd.next(rangeL, rangeR);
        }
        discY[i] = ty;
        exiY[ty] = 1;
    }
    std::ranges::sort(discX);
    std::ranges::sort(discY);
    data.x = discX[x[0] + n];
    data.y = discY[y[0] + n];
    for (int i = 1; i <= n; i++)
    {
        data.points.push_back({discX[x[i] + n], discY[y[i] + n]});
    }
    shuffle(data.points.begin(), data.points.end());
    return data;
}

Data generateRandom(int n, LL rangeL, LL rangeR)
{
    Data data;
    data.n = n;
    data.x = rnd.next(rangeL, rangeR);
    data.y = rnd.next(rangeL, rangeR);
    std::map<std::pair<LL, LL>, int> exi;
    for (int i = 1; i <= n; i++)
    {
        LL tx = rnd.next(rangeL, rangeR);
        LL ty = rnd.next(rangeL, rangeR);
        while (exi[{tx, ty}] == 1 || tx == data.x || ty == data.y)
        {
            tx = rnd.next(rangeL, rangeR);
            ty = rnd.next(rangeL, rangeR);
        }
        exi[{tx, ty}] = 1;
        data.points.push_back({tx, ty});
    }
    return data;
}
Data generateClash(int n, LL rangeL, LL rangeR, int fixTime, bool randomOrOk)
{
    Data data;
    if (randomOrOk)
        data = generateOK(n, rangeL, rangeR);
    else
        data = generateRandom(n, rangeL, rangeR);
    fixTime = std::min(fixTime, n - 1);
    std::map<std::pair<LL, LL>, int> exi;
    for (int i = fixTime; i < n; i++)
    {
        exi[{data.points[i].first, data.points[i].second}] = 1;
    }
    for (int i = 0; i < fixTime; i++)
    {
        int type = rnd.next(0, 1);
        if (type == 0)
        {
            int nxt = rnd.next(fixTime, n - 1);
            int newY = data.points[nxt].second;
            int newX = rnd.next(rangeL, rangeR);
            while (exi[{newX, newY}] == 1 || newX == data.x)
            {
                newX = rnd.next(rangeL, rangeR);
            }
            data.points[i] = {newX, newY};
        }
        else
        {
            int nxt = rnd.next(fixTime, n - 1);
            int newX = data.points[nxt].first;
            int newY = rnd.next(rangeL, rangeR);
            while (exi[{newX, newY}] == 1 || newY == data.y)
            {
                newY = rnd.next(rangeL, rangeR);
            }
            data.points[i] = {newX, newY};
        }
        exi[{data.points[i].first, data.points[i].second}] = 1;

    }
    return data;
}



int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    setName("Generate the input of In Filtration, Random Data");
    int tc = opt<int>("tc");
    int totalN = opt<int>("tN");
    int nL = opt<int>("nL");
    int nR = opt<int>("nR");
    int rangeOption = opt<int>("rO");
    int tL = opt<int>("tL");
    int tR = opt<int>("tR");
    auto ns = generateSequence(tc, nL, nR, totalN);
    cout << tc << endl;
    for (auto i : ns)
    {
        int rangeL = 1, rangeR = 200;
        if (rangeOption == 0)
        {
            rangeL = 1;
            rangeR = 20;
        }
        if (rangeOption == 1)
        {
            rangeL = 1;
            rangeR = 200;
        }
        if (rangeOption == 2)
        {
            rangeL = 1;
            rangeR = 1'000'000'000;
        }
        if (rangeOption == 3)
        {
            rangeL = 999'000'000;
            rangeR = 1'000'000'000;
        }
        if (rangeOption == 4)
        {
            rangeL = 1'000'000'000 - 200;
            rangeR = 1'000'000'000;
        }
        int genType = rnd.next(tL, tR);
        if (genType <= 40)
        {
            Data data = generateOK(i, rangeL, rangeR);
            outputData(data);
        }
        if (genType > 40 && genType <= 95)
        {
            Data data = generateRandom(i, rangeL, rangeR);
            outputData(data);
        }
        if (genType > 95)
        {
            int t1 = rnd.next(1, 5);
            int t2 = rnd.next(0, 1);
            Data data = generateClash(i, rangeL, rangeR, t1, t2);
            outputData(data);
        }
    }


}
