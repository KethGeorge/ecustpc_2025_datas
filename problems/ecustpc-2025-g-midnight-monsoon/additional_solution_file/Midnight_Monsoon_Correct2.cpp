#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

struct Info
{
    int cnt;
    LL tot;
    LL sum;
    Info() : cnt(0), tot(0), sum(0) {}
    Info(int cnt, LL tot, LL sum) : cnt(cnt), tot(tot), sum(sum) {}
};

inline Info operator+(const Info &a, const Info &b)
{
    Info res;
    res.cnt = a.cnt + b.cnt;
    res.tot = a.tot + b.tot + b.sum * a.cnt - a.sum * b.cnt;
    res.sum = a.sum + b.sum;
    return res;
}
class segTree
{
private:
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((rtL + rtR) >> 1)

    std::vector<Info> info;

    void push_up(int rt)
    {
        info[rt] = info[ls] + info[rs];
    }

    void _update(int rt, int rtL, int rtR, int pos, const Info &v)
    {
        if (rtR - rtL == 1)
        {
            info[rt] = v;
            return;
        }
        if (pos < mid)
            _update(ls, rtL, mid, pos, v);
        else
            _update(rs, mid, rtR, pos, v);
        push_up(rt);
    }

    Info _query(int rt, int rtL, int rtR, int L, int R)
    {
        if (rtR <= L || R <= rtL)
            return Info();
        if (L <= rtL && R >= rtR)
            return info[rt];
        Info res = Info();
        if (L < mid && R > mid)
            res = _query(ls, rtL, mid, L, R) + _query(rs, mid, rtR, L, R);
        else if (L < mid)
            res = _query(ls, rtL, mid, L, R);
        else
            res = _query(rs, mid, rtR, L, R);
        return res;
    }

public:
    int n;
    segTree(int _n, Info _v = Info()) : n(_n), info(4 << std::__lg(_n))
    {
        auto build = [&](auto self, int rt, int rtL, int rtR)
        {
            if (rtR - rtL == 1)
            {
                info[rt] = _v;
                return;
            }
            self(self, ls, rtL, mid);
            self(self, rs, mid, rtR);
            push_up(rt);
        };
        build(build, 1, 0, _n);
    }
    segTree(std::vector<Info> &_init) : n(_init.size()), info(4 << std::__lg(_init.size()))
    {
        auto build = [&](auto self, int rt, int rtL, int rtR)
        {
            if (rtR - rtL == 1)
            {
                info[rt] = _init[rtL];
                return;
            }
            self(self, ls, rtL, mid);
            self(self, rs, mid, rtR);
            push_up(rt);
        };
        build(build, 1, 0, n);
    }
    int binary(int rt, int rtL, int rtR, int x)
    {
        if (rtR - rtL == 1)
        {
            return rtL;
        }
        if (info[ls].cnt >= x)
            return binary(ls, rtL, mid, x);
        else
            return binary(rs, mid, rtR, x - info[ls].cnt);
    }
    void update(int pos, const Info &v) { _update(1, 0, n, pos, v); }
    Info query(int L, int R) { return _query(1, 0, n, L, R); }
    int kth_pos(int k) { return binary(1, 0, n, k); }
#undef ls
#undef rs
#undef mid
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> discre;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        discre.push_back(a[i]);
    }

    auto copyA = a;
    vector<pair<int, int>> queries(m);
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first -= 1;
        copyA[queries[i].first] += queries[i].second;
        discre.push_back(copyA[queries[i].first]);
    }

    std::ranges::sort(discre);
    discre.erase(std::unique(discre.begin(), discre.end()), discre.end());

    auto getId = [&](int x)
    {
        return (int)(std::lower_bound(discre.begin(), discre.end(), x) - discre.begin());
    };
    int discreSize = discre.size();
    vector<Info> cnt(discre.size(), Info());

    
    for (int i = 0; i < n; i++)
    {
        int id = getId(a[i]);
        cnt[id].cnt += 1;
        cnt[id].sum += a[i];
    }

    segTree tree(cnt);

    LL ans = tree.query(0, discreSize).tot;

    auto prefix_sum_by_count = [&](int t) -> LL
    {
        if (t <= 0)
            return 0LL;
        int pos = tree.kth_pos(t);
        Info L = tree.query(0, pos);
        LL take_here = t - L.cnt;
        return L.sum + take_here * 1LL * discre[pos];
    };
    auto kth_value = [&](int k) -> LL
    {
        int pos = tree.kth_pos(k);
        return 1LL * discre[pos];
    };

    for (auto [id, delt] : queries)
    {
        int oldId = getId(a[id]);
        Info oldInfo = tree.query(oldId, oldId + 1);
        oldInfo.cnt -= 1;
        oldInfo.sum -= a[id];
        tree.update(oldId, oldInfo);

        a[id] += delt;

        int newID = getId(a[id]);
        Info newInfo = tree.query(newID, newID + 1);
        newInfo.cnt += 1;
        newInfo.sum += a[id];
        tree.update(newID, newInfo);

        if (n % 2 == 0)
        {
            int k = n / 2;
            LL S = tree.query(0, discreSize).sum;
            LL pre_k_1 = prefix_sum_by_count(k - 1);
            LL s_k = kth_value(k);
            LL s_k1 = kth_value(k + 1);
            LL suf_k2 = S - prefix_sum_by_count(k + 1);

            LL ans_expr = -2 * pre_k_1 - s_k + s_k1 + 2 * suf_k2;
            LL tot = tree.query(0, discreSize).tot;
            cout << tot - ans_expr << endl;
        }
        if (n % 2 == 1)
        {
            int k = n / 2;
            LL S = tree.query(0, discreSize).sum;
            LL pre_k1 = prefix_sum_by_count(k - 1);
            LL s_k = kth_value(k);
            LL s_k1 = kth_value(k + 1);
            LL s_k2 = kth_value(k + 2);
            LL suf_k2 = S - prefix_sum_by_count(k + 2);
            LL res1 = -2 * pre_k1 - 2 * s_k + s_k1 + s_k2 + 2 * suf_k2;
            LL res2 = -2 * pre_k1 - s_k - s_k1 + 2 * s_k2 + 2 * suf_k2;
            LL tot = tree.query(0, discreSize).tot;
            cout << tot - std::max(res1, res2) << endl;
        }
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