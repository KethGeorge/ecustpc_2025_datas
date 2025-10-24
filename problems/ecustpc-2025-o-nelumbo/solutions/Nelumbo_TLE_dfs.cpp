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
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Z ans = 0;
    auto dfs = [&](auto self, int at, int fa, int minV, int gcdV) -> void
    {
        if (minV == gcdV && fa != -1)
        {
            ans += minV;
        }
        for (int y : g[at])
        {
            if (y == fa)
            {
                continue;
            }
            self(self, y, at, std::min(minV, a[y]), std::gcd(gcdV, a[y]));
        }
    };

    for (int i = 0; i < n; i++)
    {
        dfs(dfs, i, -1, a[i], a[i]);
    }
    Z pairs = Z(n) * Z(n - 1);
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