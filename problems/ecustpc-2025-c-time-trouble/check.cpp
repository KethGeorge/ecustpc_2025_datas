#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    setName("Check the answer of Time Trouble");
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int testCases = inf.readInt();

    auto isDigit = [&](char C) -> bool
    {
        return (C >= '0') && (C <= '9');
    };

    auto CheckString = [&](bool type, int i, std::string T) -> pair<int, int>
    {
        if (T.size() != 5)
        {
            if (type == 0)
                quitf(_wa, "The Length of %d-th string provided by the contestant is not correct!", i);
            if (type == 1)
                quitf(_fail, "CRASHED: The Length of %d-th string provided by the Jury is not correct!", i);
        }
        if (!isDigit(T[0]) || !isDigit(T[1]) || !isDigit(T[3]) || !isDigit(T[4]) || T[2] != ':')
        {
            if (type == 0)
                quitf(_wa, "The format of %d-th string provided by the contestant  is not correct!", i);
            if (type == 1)
                quitf(_fail, "CRASHED: The format of %d-th string provided by the Jury is not correct!", i);
        }
        pair<int, int> ansT = {(T[0] - '0') * 10 + T[1] - '0', (T[3] - '0') * 10 + T[4] - '0'};
        if (ansT.first >= 24 || ansT.second >= 60)
        {
            if (type == 0)
                quitf(_wa, "The hour or minute of %d-th string provided by the contestant is out of range!", i);
            if (type == 1)
                quitf(_fail, "The hour or minute of %d-th string provided by the contestant is out of range!", i);
        }
        if (ansT.first > ansT.second)
            std::swap(ansT.first, ansT.second);
        return ansT;
    };
    int i = 0;
    while (!ans.seekEof() && !ouf.seekEof())
    {
        i += 1;
        std::string ansTime = ans.readToken("[0123456789:-]{1,100}", "ans");
        std::string outTime = ouf.readToken("[0123456789:-]{1,100}", "output");
        while (ansTime.size() > 0 && ansTime.back() == ' ')
            ansTime.pop_back();
        while (outTime.size() > 0 && outTime.back() == ' ')
            outTime.pop_back();
        if (ansTime == "-1")
        {
            if (outTime != "-1")
            {
                quitf(_wa, "There is no legal Answer while the contestant output one!");
            }
            continue;
        }
        if (outTime == "-1")
        {
            quitf(_wa, "Jury find a legal answer while the contestant does not!");
        }
        auto ansT = CheckString(1, i, ansTime);
        auto outT = CheckString(0, i, outTime);

        if (ansT != outT)
            quitf(_wa, "The %d-th time given by the contestant is not correct!", i);
    }


    int extraAns = 0;

    while (!ans.seekEof())
    {
        ans.readLine();
        extraAns++;
    }

    int extraOut = 0;

    while (!ouf.seekEof())
    {
        ouf.readToken("[0123456789:-]{1,100}", "output");
        extraOut++;
    }
    
    if (testCases != i + extraAns)
        quitf(_fail, "CRASHED: Answer contains incorrect lines!");

    if (extraAns > 0)
        quitf(_wa, "Answer contains longer sequence [length = %d], but output contains %d elements",
              i + extraAns, i);

    if (extraOut > 0)
        quitf(_wa, "Output contains longer sequence [length = %d], but answer contains %d elements",
              i + extraOut, i);

    quitf(_ok, "%d times are correct.", testCases);

    return 0;
}
