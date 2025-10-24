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
int Mint<0>::MOD = 9;

template <int V, int P>
constexpr Mint<P> Cinv = Mint<P>(V).inv();

constexpr int P = 9; // 可以修改这里的P 如果需要将变量设为P,需要将P变为0
using Z = Mint<P>;

vector<vector<Z>> mul(const vector<vector<Z>> &A, const vector<vector<Z>> &B)
{
    int n = (int)A.size();
    int m = (int)B[0].size();
    int p = (int)A[0].size();
    vector<vector<Z>> C(n, vector<Z>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

vector<vector<Z>> power(const vector<vector<Z>> &A, long long b)
{
    int n = (int)A.size();
    vector<vector<Z>> res(n, vector<Z>(n));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    for (auto x = A; b; b >>= 1, x = mul(x, x))
        if (b & 1)
            res = mul(res, x);
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<Z>> A(20, vector<Z>(20));
    for (int i = 0; i < 10; i++)
    {
        int sq = i * i;
        A[sq % 10][i] = 1;
        if (sq > 10)
            A[sq / 10][i] = 1;
        A[i][i + 10] = 1;
        A[i + 10][i + 10] = 1;
    }
    auto finalM = power(A, m + 1);
    vector<vector<Z>> res(10, vector<Z>(10));
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            res[i][j] = finalM[i][j + 10];
    vector<vector<Z>> init(10, vector<Z>(1));
    while (n > 0)
    {
        init[n % 10][0] += 1;
        n /= 10;
    }
    auto res3 = mul(res, init);
    Z ans = 0;
    for (int i = 0; i < 10; i++)
        ans += res3[i][0] * i;
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