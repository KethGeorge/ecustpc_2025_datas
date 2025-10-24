#include <bits/stdc++.h>
using namespace std;

// ---------- 公共小工具 ----------
static inline int mod9(long long x)
{
    x %= 9;
    if (x < 0)
        x += 9;
    return (int)x;
}

// d^2 的十进制展开（最多两位）
static inline pair<int, int> sqSplit(int d)
{
    int sq = d * d;
    if (sq < 10)
        return {sq, -1};
    return {sq / 10, sq % 10}; // 十位、个位
}

// 计算一个“数字向量”的 (mod 9) 值：sum(digits) mod 9
static inline int value_mod9_from_digits(const vector<int> &a)
{
    long long s = 0;
    for (int d : a)
        s += d;
    return mod9(s);
}

// 计算 0~9 计数向量的 (mod 9) 值：sum(d * cnt[d]) mod 9
static inline int value_mod9_from_counts(const array<int, 10> &cnt)
{
    long long s = 0;
    for (int d = 0; d < 10; ++d)
        s += 1LL * d * cnt[d];
    return mod9(s);
}

// ---------- 方案 A：真·暴力（展开整串） ----------
int solve_brutal_string(long long n, long long m)
{
    // 拆初始 n 的十进制到向量
    if (n == 0)
        return mod9(0 + 0); // 先不急，统一流程也可
    vector<int> cur;
    if (n == 0)
        cur.push_back(0);
    while (n > 0)
    {
        cur.push_back(n % 10);
        n /= 10;
    }
    reverse(cur.begin(), cur.end());

    int ans = value_mod9_from_digits(cur); // t=0
    for (long long t = 1; t <= m; ++t)
    {
        vector<int> nxt;
        nxt.reserve(cur.size() * 2);
        for (int d : cur)
        {
            auto [hi, lo] = sqSplit(d);
            if (hi >= 0)
                nxt.push_back(hi);
            if (lo >= 0)
                nxt.push_back(lo);
        }
        cur.swap(nxt);
        ans = mod9(ans + value_mod9_from_digits(cur));
        // 若要保险一点避免极端爆内存，可在此加早停或阈值判断
    }
    return ans;
}

// ---------- 方案 B：计数推进（O(m)） ----------
int solve_brutal_counts(long long n, long long m)
{
    array<int, 10> cnt{}; // 这里直接维护 mod 9 的计数即可
    if (n == 0)
        cnt[0] = 1;
    while (n > 0)
    {
        cnt[n % 10] = mod9(cnt[n % 10] + 1);
        n /= 10;
    }

    int ans = value_mod9_from_counts(cnt); // t=0
    for (long long t = 1; t <= m; ++t)
    {
        array<int, 10> nxt{}; // 全 0（mod 9）
        for (int d = 0; d <= 9; ++d)
        {
            int k = cnt[d]; // 计数在 mod 9 下
            if (!k)
                continue;
            auto [hi, lo] = sqSplit(d);
            if (hi >= 0)
                nxt[hi] = (nxt[hi] + k) % 9;
            if (lo >= 0)
                nxt[lo] = (nxt[lo] + k) % 9;
        }
        cnt = nxt;
        ans = mod9(ans + value_mod9_from_counts(cnt));
    }
    return ans;
}

// ---------- 演示用 main ----------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        long long n, m;
        cin >> n >> m;

        // 两个答案都算一遍（你也可以注释掉其一）
        int a = solve_brutal_counts(n, m); // 真·暴力
        cout << a << "\n";
    }
    return 0;
}