
#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void solve()
{
    const int INF = 2'000'000'000;
    int n;
    int X, Y;
    cin >> n >> X >> Y;
    vector<pair<int, int>> points(n);
    std::map<pair<int, int>, int> mp;
    std::map<int, int> xCnt, yCnt;
    for (auto &[x, y] : points)
    {
        cin >> x >> y;
        mp[{x, y}] += 1;
        xCnt[x] += 1;
        yCnt[y] += 1;
    }
    vector<int> xL(1, -INF), yL(1, -INF), xR(1, INF), yR(1, INF);
    for (auto &[x, y] : points)
    {
        if (xCnt[x] >= 2 || yCnt[y] >= 2)
        {
            cout << "NO" << endl;
            return;
        }
        if (x < X)
        {
            xL.push_back(x);
        }
        if (x > X)
        {
            xR.push_back(x);
        }
        if (y < Y)
        {
            yL.push_back(y);
        }
        if (y > Y)
        {
            yR.push_back(y);
        }
    }
    std::ranges::sort(xL);
    std::ranges::sort(xR);
    std::ranges::sort(yL);
    std::ranges::sort(yR);
    int atxL = (int)xL.size() - 1, atxR = 0, atyL = (int)yL.size() - 1, atyR = 0;
    for (int i = 1; i <= n; i++)
    {
        int xLpos = xL[atxL];
        int xRpos = xR[atxR];
        int yLpos = yL[atyL];
        int yRpos = yR[atyR];
        if (mp[{xLpos, yLpos}] == 1)
        {
            atxL -= 1;
            atyL -= 1;
            continue;
        }
        if (mp[{xLpos, yRpos}] == 1)
        {
            atxL -= 1;
            atyR += 1;
            continue;
        }
        if (mp[{xRpos, yLpos}] == 1)
        {
            atxR += 1;
            atyL -= 1;
            continue;
        }
        if (mp[{xRpos, yRpos}] == 1)
        {
            atxR += 1;
            atyR += 1;
            continue;
        }
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int testcases = 1;
    cin >> testcases;
    for (int i = 1; i <= testcases; i++)
        solve();
}