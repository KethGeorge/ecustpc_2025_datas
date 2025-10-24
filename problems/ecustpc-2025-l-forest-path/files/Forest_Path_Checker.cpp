#include <bits/stdc++.h>
#include "testlib.h"
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

static vector<vector<int>> buildGraph(int n, const vector<pair<int, int>> &edges)
{
    vector<vector<int>> g(n);
    g.reserve(n);
    for (auto [u, v] : edges)
    {
        u -= 1;
        v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    return g;
}

vector<long long> sumDistancesBrute(int n, const vector<pair<int, int>> &edges)
{
    auto g = buildGraph(n, edges);
    vector<long long> ans(n, 0);
    vector<int> dist(n, -1);
    std::deque<int> dq;

    for (int s = 0; s < n; ++s)
    {
        fill(dist.begin(), dist.end(), -1);
        dq.clear();
        dist[s] = 0;
        dq.push_back(s);
        long long acc = 0;
        while (!dq.empty())
        {
            int u = dq.front();
            dq.pop_front();
            acc += dist[u];
            for (int v : g[u])
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    dq.push_back(v);
                }
        }
        ans[s] = acc;
    }
    return ans;
}

vector<long long> sumDistancesUnicyclic(int n, const vector<pair<int, int>> &edges, bool type)
{
    std::map<pair<int, int>, int> edgeCount;
    for (auto [u, v] : edges)
    {
        if (u > v)
            std::swap(u, v);
        edgeCount[{u, v}]++;
        if (edgeCount[{u, v}] > 1)
        {
            if (type)            
            quitf(_wa, "The contestant has multiple edges between %d and %d", u, v);
            else
            quitf(_fail, "CRASH - Multiple edges between %d and %d", u, v);
        }
    }
    auto g = buildGraph(n, edges);
    const int m_edges = (int)edges.size();

    // 1) 剥叶找环节点
    vector<int> deg(n);
    std::queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        deg[i] = (int)g[i].size();
        if (deg[i] == 1)
            q.push(i);
    }
    vector<int> alive(n, 1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        alive[u] = 0;
        for (int v : g[u])
            if (alive[v])
            {
                if (--deg[v] == 1)
                    q.push(v);
            }
    }
    vector<int> inCycle(n, 0);
    for (int i = 0; i < n; ++i)
        inCycle[i] = (deg[i] >= 2);

    // 如果没有环（纯树），用标准树换根（以 0 为根）
    auto solveTree = [&]()
    {
        vector<long long> ans(n), down(n);
        vector<int> sz(n);
        // 迭代后序避免递归爆栈
        vector<int> parent(n, -1), order;
        order.reserve(n);
        order.push_back(0);
        for (size_t i = 0; i < order.size(); ++i)
        {
            int u = order[i];
            for (int v : g[u])
                if (v != parent[u])
                {
                    parent[v] = u;
                    order.push_back(v);
                }
        }
        // 后序
        for (int i = (int)order.size() - 1; i >= 0; --i)
        {
            int u = order[i];
            sz[u] = 1;
            down[u] = 0;
            for (int v : g[u])
                if (v != parent[u])
                {
                    sz[u] += sz[v];
                    down[u] += down[v] + sz[v];
                }
        }
        ans[0] = down[0];
        // 换根
        for (int i = 0; i < (int)order.size(); ++i)
        {
            int u = order[i];
            for (int v : g[u])
                if (v != parent[u])
                {
                    ans[v] = ans[u] + (long long)n - 2LL * sz[v];
                }
        }
        return ans;
    };

    bool hasCycle = false;
    for (int x : inCycle)
        if (x)
        {
            hasCycle = true;
            break;
        }
    if (!hasCycle)
        return solveTree(); // m_edges==n-1 的退化情形

    // 2) 把环节点按顺序串起来
    vector<int> cyc;
    int start = -1;
    for (int i = 0; i < n; ++i)
        if (inCycle[i])
        {
            start = i;
            break;
        }
    int prev = -1, cur = start;
    do
    {
        cyc.push_back(cur);
        int nxt = -1;
        for (int v : g[cur])
            if (inCycle[v] && v != prev)
            {
                nxt = v;
                break;
            }
        prev = cur;
        cur = nxt;
    } while (cur != start);
    int m = (int)cyc.size();

    // 3) 对每个环点的“组件”做树 DP（只走非环边）
    vector<long long> B(n, 0);       // B[c]：环点 c 到本组件内的距离和
    vector<long long> compSum(n, 0); // 任一点 u 到本组件内的距离和
    vector<int> compRoot(n, -1);     // entry(u) -> 所属环点 c
    vector<int> depthToCycle(n, 0);  // u 到环的距离 d_u
    vector<int> compSizeAtC(n, 0);   // w_c

    vector<char> seen(n, 0);
    vector<int> parent(n, -1);

    for (int c : cyc)
    {
        // 收集该组件的所有点（阻断到其他环点的边）
        vector<int> order;
        order.reserve(16);
        std::stack<int> st;
        st.push(c);
        seen[c] = 1;
        compRoot[c] = c;
        depthToCycle[c] = 0;
        parent[c] = -1;

        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            order.push_back(u);
            for (int v : g[u])
            {
                if (inCycle[v] && v != c)
                    continue; // 不跨到其他环点
                if (!seen[v])
                {
                    seen[v] = 1;
                    compRoot[v] = c;
                    depthToCycle[v] = depthToCycle[u] + (u == c ? 1 : 1); // 每条非环边 +1
                    parent[v] = u;
                    st.push(v);
                }
            }
        }

        int W = (int)order.size(); // 组件大小 w_c
        compSizeAtC[c] = W;

        // 建立局部 id 与孩子表
        vector<int> id(n, -1);
        for (int i = 0; i < W; ++i)
            id[order[i]] = i;
        vector<vector<int>> ch(W);
        int rootId = id[c];
        for (int i = 0; i < W; ++i)
        {
            int u = order[i];
            if (u == c)
                continue;
            int pu = parent[u];
            ch[id[pu]].push_back(id[u]);
        }

        // 后序（非递归）
        vector<int> sz(W, 0);
        vector<long long> down(W, 0), ansLocal(W, 0);
        vector<pair<int, int>> stk;
        stk.reserve(W * 2);
        stk.emplace_back(rootId, 0);
        while (!stk.empty())
        {
            auto [u, state] = stk.back();
            stk.pop_back();
            if (state == 0)
            {
                stk.emplace_back(u, 1);
                for (int v : ch[u])
                    stk.emplace_back(v, 0);
            }
            else
            {
                long long d = 0;
                int s = 1;
                for (int v : ch[u])
                {
                    s += sz[v];
                    d += down[v] + sz[v];
                }
                sz[u] = s;
                down[u] = d;
            }
        }
        ansLocal[rootId] = down[rootId];

        // 换根（BFS/队列）
        std::queue<int> qq;
        qq.push(rootId);
        while (!qq.empty())
        {
            int u = qq.front();
            qq.pop();
            for (int v : ch[u])
            {
                ansLocal[v] = ansLocal[u] + (long long)W - 2LL * sz[v];
                qq.push(v);
            }
        }

        for (int u : order)
            compSum[u] = ansLocal[id[u]];
        B[c] = compSum[c];
    }

    // 4) 在环上一次性算 S1(c) = sum_t w_t * cycDist(c, c_t)
    vector<long long> w(m);
    long long Bsum = 0;
    for (int i = 0; i < m; ++i)
    {
        w[i] = compSizeAtC[cyc[i]];
        Bsum += B[cyc[i]];
    }
    int K = m / 2;
    vector<int> idxOnC(n, -1);
    // K = m/2; 已有
    // 把权数组复制成 3m 长度
    vector<long long> Wdup(3 * m), P(3 * m, 0), Q(3 * m, 0);
    for (int i = 0; i < 3 * m; ++i)
        Wdup[i] = w[i % m];
    for (int i = 0; i < 3 * m; ++i)
    {
        P[i] = Wdup[i] + (i ? P[i - 1] : 0);
        Q[i] = Wdup[i] * i + (i ? Q[i - 1] : 0);
    }
    auto pref = [&](const vector<long long> &A, int l, int r) -> long long
    {
        if (l > r)
            return 0LL;
        return A[r] - (l ? A[l - 1] : 0LL);
    };

    vector<long long> S1(m, 0);
    for (int i = 0; i < m; ++i)
    {
        int base = i + m;                       // 把中心放到中段，保证任何窗口都在 [0, 3m)
        int lNear = base + 1, rNear = base + K; // 近侧（长度 K）
        long long cntNear = pref(P, lNear, rNear);
        long long sumPosNear = pref(Q, lNear, rNear);
        long long Near = sumPosNear - 1LL * base * cntNear; // Σ w[j] * (j - base)

        int Lall = base + 1, Rall = base + m - 1; // 除自身外的 m-1 个
        long long cntAll = pref(P, Lall, Rall);
        long long sumPosAll = pref(Q, Lall, Rall);
        long long cntFar = cntAll - cntNear;
        long long sumPosFar = sumPosAll - sumPosNear;
        long long Far = 1LL * m * cntFar - (sumPosFar - 1LL * base * cntFar); // Σ w[j] * (m - (j-base))

        S1[i] = Near + Far;
    }
    for (int i = 0; i < m; ++i)
        idxOnC[cyc[i]] = i;

    // 5) 汇总答案
    vector<long long> ans(n, 0);
    for (int u = 0; u < n; ++u)
    {
        int c = compRoot[u];
        int k = idxOnC[c];
        long long comp = compSum[u];
        long long cross =
            1LL * depthToCycle[u] * (n - compSizeAtC[c]) + // 先上环再下去的垂直段
            S1[k] +                                        // 环上水平段
            (Bsum - B[c]);                                 // 对方组件内部段
        ans[u] = comp + cross;
    }
    return ans;
}
// ---------- 线性做法：基环树 / 退化树 ----------
// 复杂度 O(n)，空间 O(n)

void checkTestcase()
{
    int n = inf.readInt();
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++)
    {
        int u = inf.readInt(1, n);
        int v = inf.readInt(1, n);
        edges.push_back({u, v});
    }
    auto edges2 = edges;
    int x1 = ouf.readInt(1, n, "x");
    int y1 = ouf.readInt(1, n, "y");
    if (x1 == y1)
        quitf(_wa, "The contestant adds a self-loop on node %d", x1);
    edges.push_back({x1, y1});
    int x2 = ans.readInt(1, n);
    int y2 = ans.readInt(1, n);
    if (x2 == y2)
        quitf(_fail, "CRASH - The answer adds a self-loop on node %d", x2);
    edges2.push_back({x2, y2});
    
    auto res1 = sumDistancesUnicyclic(n, edges, true);
    auto res2 = sumDistancesUnicyclic(n, edges2, false);

    vector<LL> dist(n);
    for (int i = 0; i < n; i++)
        dist[i] = inf.readLong((LL)-1e15, (LL)1e15);

    for (int i = 0; i < n; i++)
    {
        if (res1[i] != dist[i])
            quitf(_wa, "Output distance for node %d is %lld, but expected %lld", i + 1, res1[i], dist[i]);
        if (res2[i] != dist[i])
            quitf(_fail, "CRASH - Answer distance for node %d is %lld, but expected %lld", i + 1, res2[i], dist[i]);
    }
    if (x1 > y1)
        std::swap(x1, y1);
    if (x2 > y2)
        std::swap(x2, y2);
    if (x1 != x2 || y1 != y2)
        quitf(_fail, "CRASH - Output edge (%d, %d) differs from answer edge (%d, %d)", x1, y1, x2, y2);
}
int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    setName("Check the answer of Forest Path");
    int testCases = inf.readInt();
    for (int i = 0; i < testCases; i++)
        checkTestcase();

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

    if (extraAns > 0)
        quitf(_fail, "CRASH - Answer contains too many elements [length = %d], but there should be %d elements",
              2 * testCases + extraAns, 2 * testCases);

    if (extraOut > 0)
        quitf(_wa, "Output contains too many elements [length = %d], but there should be %d elements",
              2 * testCases + extraOut, 2 * testCases);

    quitf(_ok, "%d test cases are correct.", testCases);

    return 0;
}
//.\Forest_Path_Checker input1.in output1.out ans1.ans
