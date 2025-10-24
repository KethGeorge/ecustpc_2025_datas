#include <bits/stdc++.h>
typedef int64_t LL;
using namespace std;

// ------- TLE 根因之处：把上限开很大，并在每个测试用例里整段清零 -------
const int MAXN = 100000;             // 上限，故意不小
static LL A[MAXN + 5];
static LL pref[MAXN + 5];
static LL scratch1[MAXN + 5];        // 没实际用途，只为演示 memset 代价
static LL scratch2[MAXN + 5];        // 没实际用途，只为演示 memset 代价

inline LL rangeSum(int l, int r) {   // [l, r] 前缀和区间求和
    if (l > r) return 0;
    return pref[r] - (l ? pref[l - 1] : 0);
}

void solve_one() {
    int n;
    LL x, y;
    cin >> n >> x >> y;

    // ------- TLE 点：每个用例都整段清零整个最大容量数组（而不是按 n 清理） -------
    memset(A, 0, sizeof(A));
    memset(pref, 0, sizeof(pref));
    memset(scratch1, 0, sizeof(scratch1));
    memset(scratch2, 0, sizeof(scratch2));

    for (int i = 0; i < n; ++i) cin >> A[i];

    if (x < y) swap(x, y);           // 统一 x >= y

    // 正确算法：排序 + 前缀和 + 分类讨论
    vector<LL> v(A, A + n);
    sort(v.begin(), v.end());        // 升序
    if (n) pref[0] = v[0];
    for (int i = 1; i < n; ++i) pref[i] = pref[i - 1] + v[i];

    LL ans = 0;                      // 允许做 0 天饭
    int m = n / 2;

    // 对每个 k 计算对应最优
    for (int k = 1; k <= m; ++k) {
        if (y >= 0) {
            // 取最大的 2k 个：x 乘最大的 k 个，y 乘次大的 k 个
            LL sumx = rangeSum(n - k,     n - 1);
            LL sumy = rangeSum(n - 2 * k, n - k - 1);
            ans = max(ans, x * sumx + y * sumy);
        } else if (x >= 0) {
            // x >= 0 > y：x 取最大的 k 个，y 取最小的 k 个
            LL sumx = rangeSum(n - k, n - 1);
            LL sumy = rangeSum(0,     k - 1);
            ans = max(ans, x * sumx + y * sumy);
        } else {
            // x < 0, y < 0 且 x >= y（x 没那么负）
            // 取最小的 2k 个：y 乘最小的 k 个，x 乘次小的 k 个
            LL sumy = rangeSum(0,       k - 1);
            LL sumx = rangeSum(k,   2 * k - 1);
            ans = max(ans, x * sumx + y * sumy);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) solve_one();
    return 0;
}