#include "testlib.h"
#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;


void Interact(int testcase)
{
    int type = inf.readInt(0, 1, "type");
    int x = inf.readInt();
    int y = inf.readInt();
    bool notConfirm = false;
    if ((x == 0 && y == 1) || (x == 0 && y == 2) || (x == 1 && y == 0) || (x == 1 && y == 1) || (x == 2 && y == 0) || (x == 2 && y == 2))
    {
        notConfirm = true;
    }
    int leftQuery = 35;
    bool findAnswer = false;
    const int bound = 200'000;
    auto judgeIn = [&](int a, int b) -> int
    {
        if (type == 1)
        {
            LL r = (LL)x * x + (LL)y * y;
            LL f1 = (LL)(x - y) * a + (LL)(x + y) * b;
            LL f2 = (LL)(x + y) * a - (LL)(x - y) * b;
            if (f1 < 0)
                f1 = -f1;
            if (f2 < 0)
                f2 = -f2;
            return f1 <= r && f2 <= r;
        }
        if (type == 0)
        {
            LL dist = (LL)a * a + (LL)b * b;
            LL r2 = (LL)x * x + (LL)y * y;
            return dist <= r2;
        }
        return -1;
    };
    while (leftQuery > 0 && !findAnswer)
    {
        std::string qType = ouf.readToken("!|?");
        if (qType == "?")
        {
            int a = ouf.readInt(-bound, bound, "a");
            int b = ouf.readInt(-bound, bound, "b");
            leftQuery -= 1;
            int res = judgeIn(a, b) ? 1 : 0;
            if (res == 1)
                cout << "IN" << endl;
            else
                cout << "OUT" << endl;
            cout.flush();
        }
        else
        {
            std::string ansType = ouf.readToken("Bumper|Kevin|NotConfirm", "ansType");
            if (ansType == "NotConfirm" && notConfirm)
            {
                cout << "Correct!" << endl;
                cout.flush();
                return;
            }
            if (ansType == "Kevin" && type == 1 && !notConfirm)
            {
                cout << "Correct!" << endl;
                cout.flush();
                return;
            }
            if (ansType == "Bumper" && type == 0 && !notConfirm)
            {
                cout << "Correct!" << endl;
                cout.flush();
                return;
            }
            cout << -2 << endl;
            quitf(_wa, "Wrong judgement on testcase %d!", testcase);
        }
    }
    cout << -1 << endl;
    quitf(_wa, "Did not answer within the query limit on testcase %d!", testcase);
}

int main(int argc, char *argv[])
{
    registerInteraction(argc, argv);
    setName("Interactor for Square The Circle");
    int testcases = inf.readInt();
    cout << testcases << endl;
    cout.flush();
    for (int i = 1; i <= testcases; i++)
        Interact(i);
    tout << 0 << endl;
    return 0;
}
