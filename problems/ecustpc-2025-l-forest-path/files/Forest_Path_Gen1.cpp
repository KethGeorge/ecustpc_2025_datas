#include "testlib.h"
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;
namespace tree_generator_by_ouuan
{
    typedef std::pair<int, int> pii;

    int defaultRandInt(int l, int r)
    {
        return rnd.next(l, r);
    }

    int (*randint)(int, int) = defaultRandInt;

    void defaultOutputEdge(std::ostream &os, int u, int pa)
    {
        if (randint(0, 1) == 0)
            os << u + 1 << ' ' << pa + 1 << std::endl;
        else
            os << pa + 1 << ' ' << u + 1 << std::endl;
    }

    void (*outputEdge)(std::ostream &, int, int) = defaultOutputEdge;

    class Tree
    {
    private:
        std::vector<int> p, id, eid;

    public:
        Tree()
        {
            p.push_back(-1);
            id.push_back(0);
        }
        Tree(int n)
        {
            assert(n > 0);
            p.push_back(-1);
            id.push_back(0);
            if (n > 1)
                random(n - 1, 0);
        }
        Tree(const std::string &s)
        {
            p.push_back(-1);
            id.push_back(0);

            std::function<unsigned int(const std::string &, unsigned int)> findComma = [](const std::string &str, unsigned int sta)
            {
                while (sta < str.size() && str[sta] != ',')
                    ++sta;
                return sta;
            };

            std::function<unsigned int(const std::string &, unsigned int)> findLetter = [](const std::string &str, unsigned int sta)
            {
                while (sta < str.size() && !isalpha(str[sta]))
                    ++sta;
                return sta;
            };

            std::function<void(const std::string &)> error = [](const std::string &func)
            {
                std::cerr << "Error: the number of parameters for " << func << " is not correct." << std::endl;
                exit(1);
            };

            unsigned int pos = 0;

            while (pos < s.size())
            {
                if (pos + 1 >= s.size())
                {
                    std::cerr << "Error: can't recognize the tree type abbreviation, it's too short.\n";
                    exit(1);
                }
                std::string type = s.substr(pos, 2);
                pos += 2;
                for_each(type.begin(), type.end(), [](char &x)
                         { x = tolower(x); });
                int nextLetter = findLetter(s, pos);
                if (type == "lh")
                {
                    int nextComma = findComma(s, pos);
                    assert(nextComma < nextLetter);
                    int n = atoi(s.substr(pos, nextComma - pos).c_str());
                    pos = nextComma + 1;
                    nextComma = findComma(s, pos);
                    assert(nextComma < nextLetter);
                    double low, high;
                    sscanf(s.substr(pos, nextComma - pos).c_str(), "%lf", &low);
                    pos = nextComma + 1;
                    nextComma = findComma(s, pos);
                    assert(nextComma < nextLetter);
                    sscanf(s.substr(pos, nextComma - pos).c_str(), "%lf", &high);
                    pos = nextComma + 1;
                    nextComma = findComma(s, pos);
                    assert(nextComma >= nextLetter);
                    int pa = atoi(s.substr(pos, nextComma - pos).c_str());
                    pos = nextLetter;
                    lowhigh(n, low, high, pa);
                    continue;
                }
                if (type == "lm")
                {
                    int nextComma = findComma(s, pos);
                    assert(nextComma < nextLetter);
                    int n = atoi(s.substr(pos, nextComma - pos).c_str());
                    pos = nextComma + 1;
                    nextComma = findComma(s, pos);
                    assert(nextComma < nextLetter);
                    int k = atoi(s.substr(pos, nextComma - pos).c_str());
                    pos = nextComma + 1;
                    nextComma = findComma(s, pos);
                    assert(nextComma < nextLetter);
                    double low, high;
                    sscanf(s.substr(pos, nextComma - pos).c_str(), "%lf", &low);
                    pos = nextComma + 1;
                    nextComma = findComma(s, pos);
                    assert(nextComma < nextLetter);
                    sscanf(s.substr(pos, nextComma - pos).c_str(), "%lf", &high);
                    pos = nextComma + 1;
                    nextComma = findComma(s, pos);
                    assert(nextComma >= nextLetter);
                    int pa = atoi(s.substr(pos, nextComma - pos).c_str());
                    pos = nextLetter;
                    lowhighMaxDegree(n, k, low, high, pa);
                    continue;
                }
                std::vector<int> par;
                while (1)
                {
                    int nextComma = findComma(s, pos);
                    par.push_back(atoi(s.substr(pos, nextComma - pos).c_str()));
                    pos = nextComma + 1;
                    if (nextComma >= nextLetter)
                    {
                        pos = nextLetter;
                        break;
                    }
                }
                if (type == "nd")
                {
                    if (par.size() == 1)
                        addNode(par[0]);
                    else
                        error("addNode");
                }
                else if (type == "rd")
                {
                    if (par.size() == 2)
                        random(par[0], par[1]);
                    else
                        error("random");
                }
                else if (type == "tl")
                {
                    if (par.size() == 3)
                        tall(par[0], par[1], par[2]);
                    else
                        error("tall");
                }
                else if (type == "ch")
                {
                    if (par.size() == 2)
                        chain(par[0], par[1]);
                    else
                        error("chain");
                }
                else if (type == "st")
                {
                    if (par.size() == 2)
                        star(par[0], par[1]);
                    else
                        error("star");
                }
                else if (type == "fl")
                {
                    if (par.size() == 2)
                        flower(par[0], par[1]);
                    else
                        error("flower");
                }
                else if (type == "md")
                {
                    if (par.size() == 3)
                        maxDegree(par[0], par[1], par[2]);
                    else
                        error("maxDegree");
                }
                else if (type == "cp")
                {
                    if (par.size() == 3)
                        complete(par[0], par[1], par[2]);
                    else
                        error("complete");
                }
                else if (type == "bi")
                {
                    if (par.size() == 2)
                        binary(par[0], par[1]);
                    else
                        error("binary");
                }
                else if (type == "cb")
                {
                    if (par.size() == 2)
                        completeBinary(par[0], par[1]);
                    else
                        error("completeBinary");
                }
                else if (type == "sw")
                {
                    if (par.size() == 2)
                        silkworm(par[0], par[1]);
                    else
                        error("silkworm");
                }
                else if (type == "al")
                {
                    if (par.size() == 3)
                        addLeaves(par[0], par[1], par[2]);
                    else
                        error("addLeaves");
                }
                else
                {
                    std::cerr << "Error: can't recognize the tree type abbreviation " << type << "." << std::endl;
                    exit(1);
                }
            }
        }
        int size() const { return id.size(); }
        void addNode(int pa)
        {
            assert(pa >= 0);
            assert(pa < size());
            id.push_back(id.size());
            p.push_back(pa);
            eid.push_back(id.size() - 1);
        }
        void random(int n, int pa)
        {
            int sz = size();
            assert(n > 0);
            assert(pa >= 0);
            assert(pa < sz);
            addNode(pa);
            if (n == 1)
                return;
            if (n == 2)
            {
                addNode(sz);
                return;
            }
            std::vector<int> prufer, cnt;
            std::vector<std::vector<int>> g;
            g.resize(n);
            cnt.resize(n, 0);
            for (int i = 0; i < n - 2; ++i)
            {
                int x = randint(0, n - 1);
                prufer.push_back(x);
                ++cnt[x];
            }
            std::priority_queue<int> q;
            for (int i = 0; i < n; ++i)
                if (!cnt[i])
                    q.push(i);
            for (auto v : prufer)
            {
                int u = q.top();
                g[u].push_back(v);
                g[v].push_back(u);
                q.pop();
                if (--cnt[v] == 0)
                    q.push(v);
            }
            int x = q.top();
            q.pop();
            int y = q.top();
            g[x].push_back(y);
            g[y].push_back(x);

            std::queue<int> bfs;

            bfs.push(0);
            int _id = sz;

            while (!bfs.empty())
            {
                int u = bfs.front();
                cnt[u] = 1;
                bfs.pop();
                for (auto v : g[u])
                {
                    if (cnt[v] == 0)
                    {
                        addNode(_id);
                        bfs.push(v);
                    }
                }
                ++_id;
            }
        }
        void lowhigh(int n, double low, double high, int pa)
        {
            int sz = size();
            assert(n > 0);
            assert(low >= 0);
            assert(high <= 1);
            assert(high >= low);
            assert(pa >= 0);
            assert(pa < sz);
            addNode(pa);
            for (int i = 1; i < n; ++i)
                addNode(randint(round((i - 1) * low), round((i - 1) * high)) + sz);
        }
        void tall(int n, int k, int pa)
        {
            int sz = size();
            assert(n > 0);
            assert(k > 0);
            assert(pa >= 0);
            assert(pa < sz);
            addNode(pa);
            for (int i = sz + 1; i < sz + n; ++i)
                addNode(randint(std::max(sz, i - k), i - 1));
        }
        void chain(int n, int pa)
        {
            assert(n > 0);
            assert(pa >= 0);
            assert(pa < size());
            tall(n, 1, pa);
        }
        void star(int n, int pa)
        {
            int sz = size();
            assert(n > 0);
            assert(pa >= 0);
            assert(pa < sz);
            addNode(pa);
            for (int i = sz + 1; i < sz + n; ++i)
                addNode(sz);
        }
        void flower(int n, int pa)
        {
            assert(n > 0);
            assert(pa >= 0);
            assert(pa < size());
            star(n, pa);
        }
        void maxDegree(int n, int k, int pa)
        {
            int sz = size();
            assert(n > 0);
            assert(k >= 2);
            assert(pa >= 0);
            assert(pa < sz);
            addNode(pa);
            __gnu_pbds::tree<pii, __gnu_pbds::null_type, std::less<pii>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> remain;
            remain.insert(pii(sz, k - 1));
            for (int i = sz + 1; i < sz + n; ++i)
            {
                auto it = remain.find_by_order(randint(0, remain.size() - 1));
                int u = it->first;
                int t = it->second;
                remain.erase(it);
                if (t > 1)
                    remain.insert(pii(u, t - 1));
                addNode(u);
                remain.insert(pii(i, k - 1));
            }
        }
        void lowhighMaxDegree(int n, int k, double low, double high, int pa)
        {
            int sz = size();
            assert(n > 0);
            assert(k >= 2);
            assert(low >= 0);
            assert(high <= 1);
            assert(pa >= 0);
            assert(pa < sz);
            addNode(pa);
            __gnu_pbds::tree<pii, __gnu_pbds::null_type, std::less<pii>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> remain;
            remain.insert(pii(sz, k - 1));
            for (int i = sz + 1; i < sz + n; ++i)
            {
                auto it = remain.find_by_order(randint(round((remain.size() - 1) * low), round((remain.size() - 1) * high)));
                int u = it->first;
                int t = it->second;
                remain.erase(it);
                if (t > 1)
                    remain.insert(pii(u, t - 1));
                addNode(u);
                remain.insert(pii(i, k - 1));
            }
        }
        void complete(int n, int k, int pa)
        {
            int sz = size();
            assert(n > 0);
            assert(k >= 2);
            assert(pa >= 0);
            assert(pa < sz);
            addNode(pa);
            for (int i = sz + 1; i < sz + n; ++i)
                addNode(sz + ceil(1.0 * (i - sz) / (k - 1) - 1e-9) - 1);
        }
        void binary(int n, int pa)
        {
            assert(n > 0);
            assert(pa >= 0);
            assert(pa < size());
            maxDegree(n, 3, pa);
        }
        void completeBinary(int n, int pa)
        {
            assert(n > 0);
            assert(pa >= 0);
            assert(pa < size());
            complete(n, 3, pa);
        }
        void silkworm(int n, int pa)
        {
            int sz = size();
            assert(n > 0);
            assert(pa >= 0);
            assert(pa < sz);
            int chain_len = (n + 1) / 2;
            chain(chain_len, pa);
            for (int i = sz; i + chain_len < sz + n; ++i)
                addNode(i);
        }
        void addLeaves(int n, int l, int r)
        {
            assert(n > 0);
            assert(l >= 0);
            assert(r < size());
            assert(l <= r);
            for (int i = 1; i <= n; ++i)
                addNode(randint(l, r));
        }
        void shuffleNodes(int from = 0)
        {
            for (int i = 0; i < from; ++i)
                id[i] = i;
            for (unsigned int i = from; i < id.size(); ++i)
            {
                id[i] = i;
                std::swap(id[i], id[randint(from, i)]);
            }
        }
        void shuffleEdges()
        {
            for (unsigned int i = 0; i < eid.size(); ++i)
            {
                eid[i] = i + 1;
                std::swap(eid[i], eid[randint(0, i)]);
            }
        }
        void resize(int n)
        {
            assert(n > 0);
            if (size() < n)
                addLeaves(n - size(), 0, size() - 1);
            else if (size() > n)
            {
                p.resize(n);
                id.resize(n);
                eid.resize(n - 1);
                for (int i = 0; i < n; ++i)
                    id[i] = i;
                for (int i = 0; i < n - 1; ++i)
                    eid[i] = i + 1;
            }
        }
        int getSize() const { return id.size(); }
        std::vector<pair<int, int>> edges()
        {
            this->shuffleNodes();
            this->shuffleEdges();
            std::vector<std::pair<int, int>> out;
            for (unsigned int i = 0; i < eid.size(); ++i)
                out.push_back(std::make_pair(id[eid[i]], id[p[eid[i]]]));
            return out;
        }
        void printEdge(int edgeID, std::ostream &os = std::cout) const
        {
            outputEdge(os, id[eid[edgeID]], id[p[eid[edgeID]]]);
        }
        int parent(int u) const
        {
            return p[u];
        }
        friend std::ostream &operator<<(std::ostream &os, const Tree &t)
        {
            for (unsigned int i = 0; i < t.eid.size(); ++i)
                t.printEdge(i, os);
            return os;
        }
    };
};
using namespace tree_generator_by_ouuan;

struct Data
{
    int n;
    std::vector<std::pair<int, int>> edges;
    vector<LL> a;
};
static vector<vector<int>> buildGraph(int n, const vector<pair<int, int>> &edges)
{
    vector<vector<int>> g(n);
    g.reserve(n);
    for (auto [u, v] : edges)
    {
        // u -= 1;
        // v -= 1;
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

// ---------- 线性做法：基环树 / 退化树 ----------
// 复杂度 O(n)，空间 O(n)
vector<long long> sumDistancesUnicyclic(int n, const vector<pair<int, int>> &edges)
{
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

Data generate(int n)
{
    Data d;
    d.n = n;
    int treeForm = rnd.next(0, 4);
    Tree t;
    if (treeForm == 0)
        t = Tree(n);
    if (treeForm == 1)
    {
        t = Tree(1);
        t.chain(n - 1, 0);
    }
    if (treeForm == 2)
    {
        t = Tree(1);
        t.star(n - 1, 0);
    }
    if (treeForm == 3)
    {
        t = Tree(1);
        int degMax = rnd.next(2, std::max(2, n / 10));
        t.maxDegree(n - 1, degMax, 0);
    }
    if (treeForm == 4)
    {
        t = Tree(1);
        t.lowhigh(n - 1, 0.3, 0.7, 0);
    }
    d.edges = t.edges();

    std::map<pair<int, int>, int> edgeSet;
    for (auto [u, v] : d.edges)
    {
        edgeSet[{u, v}] = 1;
        edgeSet[{v, u}] = 1;
    }
    int x = rnd.next(0, n - 1);
    int y = rnd.next(0, n - 1);
    while (x == y || edgeSet.count({x, y}))
    {
        x = rnd.next(0, n - 1);
        y = rnd.next(0, n - 1);
    }
    d.edges.push_back({x, y});
    d.a = sumDistancesUnicyclic(n, d.edges);
    return d;
}
void output(Data d)
{
    cout << d.n << endl;
    for (int i = 0; i < (int)d.edges.size() - 1; i++)
    {
        auto [x, y] = d.edges[i];
        cout << x + 1 << " " << y + 1 << endl;
    }
    for (int i = 0; i < d.n; i++)
    {
        cout << d.a[i] << (i == d.n - 1 ? '\n' : ' ');
    }
}

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
    setName("Generate the input of Forest Path");

    int tc = opt<int>("tc");
    int totalN = opt<int>("tN");
    int nL = opt<int>("nl");
    int nR = opt<int>("nr");
    cout << tc << endl;
    auto ns = generateSequence(tc, nL, nR, totalN);
    for (auto n : ns)
    {
        auto d = generate(n);
        output(d);
    }
}
