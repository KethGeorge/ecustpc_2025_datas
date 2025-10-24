#include <bits/stdc++.h>
#define fp(i, x, y) for (int i = (x); i <= (y); ++i)
#define fq(i, x, y) for (int i = (y); i >= (x); --i)
#define fb(i, x) for (int i = head[x]; i != -1; i = nxt[i])
#define int long long
#define ls k << 1
#define rs k << 1 | 1
using namespace std;
const int N = 4e5 + 10;
int n, m, len, a[N], b[N], id[N], dt[N], cnt[N];
int pi(int x) { return lower_bound(b + 1, b + 1 + len, x) - b; }
struct node
{
    int tot, ans, sum;
    friend node operator+(node A, node B)
    {
        node C;
        C.tot = A.tot + B.tot;
        C.sum = A.sum + B.sum;
        C.ans = A.ans + B.ans + B.sum * A.tot - A.sum * B.tot;
        return C;
    }
} t[N << 2];
void build(int k, int l, int r)
{
    if (l == r)
    {
        t[k].tot = cnt[l];
        t[k].sum = cnt[l] * b[l];
        t[k].ans = 0;
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    t[k] = t[ls] + t[rs];
}
void modify(int k, int l, int r, int x, int z)
{
    if (l == r)
    {
        t[k].sum += b[l] * z;
        t[k].tot += z;
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        modify(ls, l, mid, x, z);
    else
        modify(rs, mid + 1, r, x, z);
    t[k] = t[ls] + t[rs];
}
int erfen(int k, int l, int r, int x)
{
    if (l == r)
    {
        assert(x > 0 && x <= t[k].tot);
        return b[l];
    }
    int mid = l + r >> 1;
    if (x <= t[ls].tot)
        return erfen(ls, l, mid, x);
    else
        return erfen(rs, mid + 1, r, x - t[ls].tot);
}
int query(int k, int l, int r, int x)
{
    if (x <= 0)
        return 0;
    if (t[k].tot <= x)
        return t[k].sum;
    if (l == r)
    {
        assert(x <= t[k].tot);
        return x * b[l];
    }
    int mid = l + r >> 1;
    return query(ls, l, mid, x) + query(rs, mid + 1, r, x - t[ls].tot);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        len = 0;
        fp(i, 1, n) cin >> a[i], b[++len] = a[i];
        fp(i, 1, m) cin >> id[i] >> dt[i], a[id[i]] += dt[i], b[++len] = a[id[i]];
        fq(i, 1, m) a[id[i]] -= dt[i];
        sort(b + 1, b + 1 + len);
        len = unique(b + 1, b + 1 + len) - (b + 1);
        fp(i, 1, len) cnt[i] = 0;
        fp(i, 1, n) cnt[pi(a[i])]++;
        build(1, 1, len);
        fp(i, 1, m)
        {
            int x = id[i], y = dt[i];
            modify(1, 1, len, pi(a[x]), -1);
            a[x] += y;
            modify(1, 1, len, pi(a[x]), 1);
            if (n & 1)
            {
                int t1 = erfen(1, 1, len, n / 2),
                    t2 = erfen(1, 1, len, n / 2 + 1),
                    t3 = erfen(1, 1, len, n / 2 + 2);
                int sump = query(1, 1, len, n / 2 - 1),
                    suma = t[1].sum - sump - t1 - t2 - t3;
                int ans = max(2 * (suma + t3) - 2 * sump - t1 - t2,
                              2 * suma + t3 + t2 - 2 * (sump + t1));
                cout << t[1].ans - ans << '\n';
            }
            else
            {
                int t1 = erfen(1, 1, len, n / 2),
                    t2 = erfen(1, 1, len, n / 2 + 1);
                int sump = query(1, 1, len, n / 2 - 1),
                    suma = t[1].sum - sump - t1 - t2;
                int ans = 2 * suma + t2 - 2 * sump - t1;
                cout << t[1].ans - ans << '\n';
            }
        }
    }
}