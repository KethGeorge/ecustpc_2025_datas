
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


int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    setName("Generate the input of Clockwork");

    int testcases = opt<int>("tc");
    int totalN = opt<int>("tN");
    int nleft = opt<int>("nl");
    int nright = opt<int>("nr");

    cout << testcases << "\n";
    vector<LL> nSequences = generateSequence(testcases, nleft, nright, totalN);
    for (int t = 0; t < testcases; t++)
    {
        cout << nSequences[t] << "\n";
        int r = rnd.next(1, 4);
        if (r == 1)
        {
            for (int i = 1; i <= nSequences[t]; i++)
                cout << 1 << (i == nSequences[t] ? "\n" : " ");
        }
        if (r == 2)
        {
            for (int i = 1; i <= nSequences[t]; i++)
                cout << (i % 2 == 1 ? 1 : 2) << (i == nSequences[t] ? "\n" : " ");
        }
        if (r == 3)
        {
            for (int i = 1; i <= nSequences[t]; i++)
                cout << i << (i == nSequences[t] ? "\n" : " ");
        }
        if (r == 4)
        {
            for (int i = nSequences[t]; i >= 1; i--)
                cout << i << (i == 1 ? "\n" : " ");
        }
    }
}