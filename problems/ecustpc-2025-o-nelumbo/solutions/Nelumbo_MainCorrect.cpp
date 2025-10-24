#include <bits/stdc++.h>
typedef int64_t LL;
using std::cin, std::cout, std::endl, std::vector, std::pair;

template <typename T>
constexpr T power(T a, long long b)
{
    T res = 1;
    for (; b; b >>= 1, a *= a)
        if (b & 1)
            res *= a;
    return res;
}
template <int P>
class Mint
{
public:
    int x;
    static int MOD;
    constexpr Mint() : x() {}
    constexpr Mint(long long _x) : x{norm(_x % getMOD())} {}

    constexpr static void setMOD(int _MOD) { MOD = _MOD; }
    constexpr static int getMOD() { return P > 0 ? P : MOD; }
    constexpr int norm(int x) const { return x >= 0 && x < getMOD() ? x : (x < 0 ? x += getMOD() : x -= getMOD()); }
    constexpr int val() const { return x; }
    explicit constexpr operator int() const { return x; }
    constexpr Mint operator-() const
    {
        Mint res;
        res.x = norm(getMOD() - x);
        return res;
    }
    constexpr Mint inv() const
    {
        assert(x != 0);
        return power(*this, getMOD() - 2);
    }
    constexpr Mint &operator*=(Mint rhs) &
    {
        x = 1LL * x * rhs.x % getMOD();
        return *this;
    }
    constexpr Mint &operator+=(Mint rhs) &
    {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr Mint &operator-=(Mint rhs) &
    {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr Mint &operator/=(Mint rhs) & { return *this *= rhs.inv(); }
    friend constexpr Mint operator*(Mint lhs, Mint rhs)
    {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr Mint operator+(Mint lhs, Mint rhs)
    {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr Mint operator-(Mint lhs, Mint rhs)
    {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr Mint operator/(Mint lhs, Mint rhs)
    {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, Mint &a)
    {
        long long v;
        is >> v;
        a = Mint(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const Mint &a) { return os << a.val(); }
    friend constexpr bool operator==(Mint lhs, Mint rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(Mint lhs, Mint rhs) { return lhs.val() != rhs.val(); }
};

template <>
int Mint<0>::MOD = 998'244'353;

template <int V, int P>
constexpr Mint<P> Cinv = Mint<P>(V).inv();

constexpr int P = 998'244'353; // 可以修改这里的P 如果需要将变量设为P,需要将P变为0
using Z = Mint<P>;

// 998'244'353
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        g[x].push_back(y);
        g[y].push_back(x);
        edges.push_back({x, y});
    }
    vector<int> a(n);

    vector<vector<int>> divisor(n + 1);
    vector<vector<pair<int, int>>> cnt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            divisor[j].push_back(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (auto [x, y] : edges)
    {
        int g = std::gcd(a[x], a[y]);
        for (auto d : divisor[g])
        {
            cnt[d].push_back({x, y});
        }
    }

    auto findf = [&](auto self, vector<int> &fa, vector<int> &siz, int x) -> int
    {
        if (fa[x] != x)
            fa[x] = self(self, fa, siz, fa[x]);
        return fa[x];
    };

    auto merge = [&](vector<int> &fa, vector<int> &siz, int x, int y) -> Z
    {
        int fx = findf(findf, fa, siz, x);
        int fy = findf(findf, fa, siz, y);
        Z ans1 = 0;
        if (fx != fy)
        {
            if (siz[fx] < siz[fy])
                std::swap(fx, fy);
            fa[fy] = fx;
            ans1 += (Z)siz[fx] * (Z)siz[fy];
            siz[fx] += siz[fy];
        }
        return ans1;
    };


    vector<int> fa(n), siz(n, 1);
    std::iota(fa.begin(), fa.end(), 0);
    Z ans = 0;
    for (int k = 1; k <= n; k++)
    {
        std::queue<int> pts;
        Z res1 = 0;
        for (auto [x, y] : cnt[k])
        {
            if (a[x] != k && a[y] != k)
            {
                pts.push(x);
                pts.push(y);
                res1 += merge(fa, siz, x, y);
            }
        }
        Z res2 = res1;
        for (auto [x, y] : cnt[k])
        {
            if (a[x] == k || a[y] == k)
            {
                pts.push(x);
                pts.push(y);
                res2 += merge(fa, siz, x, y);
            }
        }
        ans += (res2 - res1) * Z(k);
        while (!pts.empty())
        {
            int x = pts.front();
            pts.pop();
            fa[x] = x;
            siz[x] = 1;
        }
    }
    Z pairs = Z(n) * Z(n - 1) / Z(2);
    ans /= pairs;
    cout << ans << endl;
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