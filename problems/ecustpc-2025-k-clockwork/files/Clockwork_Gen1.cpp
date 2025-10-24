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

vector<int> generateRandom(int size)
{
    vector<int> a(size);
    for (int i = 0; i < size; i++)
        a[i] = rnd.next(1, size);
    return a;
}

vector<int> generateLegal(int size, int opts)
{
    vector<int> a(size);
    int maxL = -1, minR = size + 1;
    for (int o = 0; o < opts; o++)
    {
        int dir = rnd.next(0, 1);
        int i = rnd.next(0, size - 1);
        if (dir == 0) // left
        {
            int cnt = 1;
            for (int j = i; j >= 0; j--)
            {
                a[j] = cnt;
                cnt += 1;
            }
            maxL = std::max(maxL, i);
        }
        if (dir == 1) // right
        {
            int cnt = 1;
            for (int j = i; j < size; j++)
            {
                a[j] = cnt;
                cnt += 1;
            }
            minR = std::min(minR, i);
        }
    }
    if (maxL < minR - 1)
    {
        int dir = rnd.next(0, 1);
        if (dir == 0)
        {
            int rB = std::min(minR - 1, size - 1);
            int i = rnd.next(rB, size - 1);
            int cnt = 1;
            for (int j = i; j >= 0; j--)
            {
                a[j] = cnt;
                cnt += 1;
            }
        }
        if (dir == 1)
        {
            int lB = std::max(maxL + 1, 0);
            int i = rnd.next(0, lB);
            int cnt = 1;
            for (int j = i; j < size; j++)
            {
                a[j] = cnt;
                cnt += 1;
            }
        }
    }
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

    int legalSize = opt<int>("l");
    cout << testcases << "\n";
    vector<LL> nSequences = generateSequence(testcases, nleft, nright, totalN);
    for (int i = 0; i < testcases; i++)
    {
        cout << nSequences[i] << "\n";
        int r = rnd.next(1, 100);
        if (r <= legalSize)
        {
            int opts = rnd.next(1, 2 * (int)nSequences[i]);
            auto a = generateLegal(nSequences[i], opts);
            for (int j = 0; j < a.size(); j++)
            {
                cout << a[j] << (j == a.size() - 1 ? "\n" : " ");
            }
        }
        else
        {
            auto a = generateRandom(nSequences[i]);
            for (int j = 0; j < a.size(); j++)
            {
                cout << a[j] << (j == a.size() - 1 ? "\n" : " ");
            }
        }
    }
}