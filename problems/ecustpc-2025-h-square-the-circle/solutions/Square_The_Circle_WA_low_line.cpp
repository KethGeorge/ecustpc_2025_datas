#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

void solve()
{
    auto Query = [](int a, int b) {
        cout << "? " << a << " " << b << endl;
        cout.flush();
        std::string res;
        cin >> res;
        return res == "IN" ? 1 : 0;
    };

    auto Answer = [](int t) {
        if (t == 0)
            cout << "! Bumper" << endl;
        else if (t == 1)
            cout << "! Kevin" << endl;
        else
            cout << "! NotConfirm" << endl;
        cout.flush();
        std::string res;
        cin >> res;
    };
    
    int l = 1, r = 200000;

    int ans1 = Query(10, 0);
    if (ans1 == 0)
        r = 10;

    int mid = (l + r) / 2;
    while (l < r)
    {
        mid = (l + r) / 2;
        int ans = Query(mid, 0);
        if (ans == 1)
            l = mid + 1;
        else
            r = mid;
    }
    mid = l - 1;
    vector<pair<int, int>> dir = {{1, 1}, {2, 1}, {1, 2}, {3, 1}, {1, 3}, {3, 2}};
    bool stop = 0;
    for (auto [dx, dy] : dir)
    {
        long double step = sqrt(1.0 * (dx * dx + dy * dy));
        int lowerbound = floor(mid / step);
        int upperbound = ceil((mid + 1) / step);
        pair<int, int> in = {lowerbound * dx, lowerbound * dy};
        pair<int, int> out = {upperbound * dx, upperbound * dy};
        if (dx == 2 && dy == 3)
            stop = 1;
        if (mid >= 10 && stop)
            break;
        if (!stop)
        {
            int ans1 = Query(in.first, in.second);
            if (ans1 == 0)
            {
                Answer(1);
                return;
            }
        }
        int ans2 = Query(out.first, out.second);
        if (ans2 == 1)
        {
            Answer(1);
            return;
        }
    }
    if (mid > 2)
        Answer(0);
    else
    {
        int cnt = Query(1, 2);
        cnt += Query(2, 1);
        cnt += Query(2, 2);
        if (cnt == 2)
            Answer(0);
        else
            Answer(2);
    }
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