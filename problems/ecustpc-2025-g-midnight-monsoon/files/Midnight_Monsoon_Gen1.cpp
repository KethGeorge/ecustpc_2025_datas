
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
        quitf(_fail, "No solution: total_sum (%lld) out of range [%lld, %lld]", total_sum, min_sum, max_sum);
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

vector<pair<LL, LL>> opts(int n, vector<LL> &a, int opts, int m)
{
    int stratOpt = rnd.next(1, 3);
    // stratOpt = 1: random
    // stratOpt = 2: few big, many small
    // stratOpt = 3: contain some zero
    // std::cerr << "stratOpt: " << stratOpt << "\n";
    vector<LL> opNum;
    if (stratOpt == 1)
    {
        if (opts < m)
            stratOpt = 3;
        else
        {            
            opNum = generateSequence(m, 1, opts, opts);
        }
    }
    if (stratOpt == 2)
    {
        if (opts < m)
        {
            stratOpt = 3;
        }
        else
        {
            int bigCnt = rnd.next(1, std::max(std::min(5, m - 1), 1));
            int smallCnt = m - bigCnt;
            int bigPart = opts * 4 / 5;
            int smallPart = opts - bigPart;
            vector<LL> big = generateSequence(bigCnt, std::max(0, bigPart / bigCnt - 2), bigPart / bigCnt + 1, bigPart);
            vector<LL> small = generateSequence(smallCnt, 0, std::max(1, smallPart / smallCnt + 1), smallPart);
            opNum.insert(opNum.end(), big.begin(), big.end());
            opNum.insert(opNum.end(), small.begin(), small.end());
            shuffle(opNum.begin(), opNum.end());
        }
    }
    if (stratOpt == 3)
    {

        int zeroCnt = rnd.next(0, std::min(5, opts / 5));
        zeroCnt = std::max(m - opts, zeroCnt);
        int otherCnt = std::max(m - zeroCnt, 1);
        int realZeroCnt = m - otherCnt;
        // std::cerr << "zeroCnt: " << zeroCnt << ", otherCnt: " << otherCnt << "\n";
        vector<LL> otherPart = generateSequence(otherCnt, 1, opts, opts);
        opNum.insert(opNum.end(), otherPart.begin(), otherPart.end());
        for (int i = 0; i < realZeroCnt; i++)
            opNum.push_back(0);
        shuffle(opNum.begin(), opNum.end());
    }
    assert((int)opNum.size() == m);
    int strat = rnd.next(1, 4);
    // strat = 1: rnd
    // strat = 2: switch large to small (|a| small)
    // strat = 3: few num wave
    // strat = 4: medium jump
    // std::cerr << "strat: " << strat << "\n";
    if (strat == 1)
    {
        vector<pair<LL, LL>> ans;
        for (auto i : opNum)
        {
            int minus = rnd.next(0, 1);
            int delt = i * (minus == 0 ? 1 : -1);
            int id = rnd.next(0, n - 1);
            ans.push_back({id, delt});
        }
        return ans;
    }

    if (strat == 2)
    {
        std::set<pair<int, int>> setA;
        for (int i = 0; i < n; i++)
            setA.insert({a[i], i});
        vector<pair<LL, LL>> ans;
        int minus = 0;
        for (auto i : opNum)
        {
            if (minus == 0)
            {
                auto it = setA.end();
                it--;
                int id = it->second;
                ans.push_back({id, (LL)i});
                setA.erase(it);
                setA.insert({a[id] + i, id});
            }
            else
            {
                auto it = setA.begin();
                int id = it->second;
                ans.push_back({id, -(LL)i});
                setA.erase(it);
                setA.insert({a[id] - i, id});
            }
        }
        return ans;
    }
    if (strat == 3)
    {
        vector<int> chosenNum;
        int chooseCnt = rnd.next(1, std::min((int)opNum.size(), 5));
        for (int i = 0; i < chooseCnt; i++)
        {
            int id = rnd.next(0, n - 1);
            chosenNum.push_back(id);
        }
        vector<pair<LL, LL>> ans;
        for (auto i : opNum)
        {
            int minus = rnd.next(0, 1);
            int id = chosenNum[rnd.next(0, chooseCnt - 1)];
            int delt = i * (minus == 0 ? 1 : -1);
            ans.push_back({id, delt});
        }
        return ans;
    }
    if (strat == 4)
    {
        auto sorted = a;
        std::ranges::sort(sorted);
        vector<pair<LL, LL>> ans;
        int lastId = n / 2;
        for (auto i : opNum)
        {
            int minus = rnd.next(0, 1);
            int delt = i * (minus == 0 ? 1 : -1);
            int id = lastId + rnd.next(-3, 3);
            id = std::min(std::max(id, 0), n - 1);
            ans.push_back({id, delt});
            lastId = id;
        }
        return ans;
    }
    return {};
}

vector<LL> generateA(int n)
{
    int strat = rnd.next(1, 6);
    // strat = 1: random
    // strat = 2: few unique
    // strat = 3: 1-n;
    // strat = 4: range small
    // strat = 5: two peak
    // strat = 6: extreme
    vector<LL> ans;
    const int maxA = 1e8;
    if (strat == 1)
    {
        for (int i = 0; i < n; i++)
            ans.push_back(rnd.next(-maxA, maxA));
        return ans;
    }
    if (strat == 2)
    {
        int uniqueCnt = rnd.next(1, std::min(10, n));
        vector<LL> uniquePart;
        for (int i = 0; i < uniqueCnt; i++)
        {
            uniquePart.push_back(rnd.next(-maxA, maxA));
        }
        for (int i = 0; i < n; i++)
            ans.push_back(uniquePart[rnd.next(0, uniqueCnt - 1)]);
        return ans;
    }
    if (strat == 3)
    {
        for (int i = 1; i <= n; i++)
            ans.push_back(i);
        shuffle(ans.begin(), ans.end());
        return ans;
    }
    if (strat == 4)
    {
        for (int i = 0; i < n; i++)
            ans.push_back(rnd.next(-100, 100));
        return ans;
    }

    if (strat == 5)
    {
        int peak1 = rnd.next(-maxA, maxA);
        int peak2 = rnd.next(-maxA, maxA);
        for (int i = 0; i < n; i++)
        {
            int r = rnd.next(0, 1);
            if (r == 0)
                ans.push_back(peak1 + rnd.next(-100, 100));
            else
                ans.push_back(peak2 + rnd.next(-100, 100));
        }
        return ans;
    }
    if (strat == 6)
    {
        int r = rnd.next(0, 1);
        if (r == 0)
        {
            for (int i = 0; i < n; i++)
                ans.push_back(maxA - rnd.next(0, 100));
        }
        else
        {
            for (int i = 0; i < n; i++)
                ans.push_back(-maxA + rnd.next(0, 100));
        }
        return ans;
    }
    return {};
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    setName("Generate the input of Midnight Monsoon");
    const int INF = 1e8;
    int testcases = opt<int>("tc");
    int totalN = opt<int>("tN");
    int nleft = opt<int>("nl");
    int nright = opt<int>("nr");
    int totalM = opt<int>("tM");
    int mleft = opt<int>("ml");
    int mright = opt<int>("mr");
    int dleft = opt<int>("dl");
    int dright = opt<int>("dr");
    if (dright == 0)
        dright = INF;
    cout << testcases << "\n";
    vector<LL> nSequences = generateSequence(testcases, nleft, nright, totalN);
    vector<LL> mSequences = generateSequence(testcases, mleft, mright, totalM);
    for (int i = 1; i <= testcases; i++)
    {
        LL n = nSequences[i - 1];
        LL m = mSequences[i - 1];
        LL d = rnd.next(dleft, dright);
        vector<LL> a = generateA(n);
        cout << n << " " << m << "\n";
        for (int j = 0; j < n; j++)
            cout << a[j] << (j == n - 1 ? "\n" : " ");
        auto ops = opts(n, a, d, m);
        for (auto [id, delt] : ops)
            cout << id + 1 << " " << delt << "\n";
    }
}
