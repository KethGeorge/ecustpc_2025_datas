#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
#define endl "\n"

void Solve()
{
    int a, b;
    cin >> a >> b;

    auto isDigit = [&](char C) -> bool
    {
        return (C >= '0') && (C <= '9');
    };

    std::string S('0', 5);
    auto Check = [&]() -> bool
    {
        if (!isDigit(S[0]) || !isDigit(S[1]) || !isDigit(S[3]) || !isDigit(S[4]) || S[2] != ':')
            return false;
        pair<int, int> ans = {(S[0] - '0') * 10 + S[1] - '0', (S[3] - '0') * 10 + S[4] - '0'};
        if (ans.first >= 24 || ans.second >= 60)
            return false;
        if ((ans.first == a && ans.second == b) || (ans.first == b && ans.second == a))
        {
            cout << std::format("{}{}:{}{}", ans.first / 10, ans.first % 10, ans.second / 10, ans.second % 10) << endl;
            return true;
        }
        return false;
    };
    auto Dfs = [&](auto self, int at) -> bool
    {
        if (at == 5)
        {
            if (Check())
                return true;
            return false;
        }
        for (char c = 48; c <= 58; c++)
        {
            S[at] = c;
            if (self(self, at + 1))
                return true;
        }
        return false;
    };

    if (!Dfs(Dfs, 0))
    {
        cout << "-1" << endl;
        return;
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
        Solve();
}