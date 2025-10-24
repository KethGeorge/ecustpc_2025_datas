#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define vec vector
#define fir first
#define sec second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mxe max_element
#define mne min_element
#define ppc __builtin_popcount
#define ctz __builtin_ctzll // 去掉define int long long记得修改这里喵
#define clz __builtin_clzll // 还有这里喵
#define pcs(n) cout << fixed << setprecision(n)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull;
typedef __int128_t lll;
const int mod = 1e9 + 7; // 1000000000039ll;
const int N = 200005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int bs = 433;
const int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
const double esp = 1e-6;

void Thirstarfish()
{
    int n;
    cin >> n;
    vec<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vec dp(2, vec<int>(n + 1, inf));
    dp[0][1] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > i && a[i] > n - i + 1)
        {
            cout << -1 << endl;
            return;
        }
        if (a[i] == a[i - 1] - 1)
            dp[0][i] = min(dp[0][i], dp[0][i - 1]);
        else if (a[i] == a[i - 1] + 1)
            dp[1][i] = min(dp[1][i], dp[1][i - 1]);
        else if (a[i] > 1 && a[i - 1] > 1)
        {
            cout << -1 << endl;
            return;
        }
        if (a[i] == 1 || a[i - 1] == 1)
            dp[1][i] = min(dp[1][i], dp[0][i - 1] + 1);
        if (a[i] == 1)
            dp[1][i] = min(dp[1][i], dp[1][i - 1] + 1);
        if (a[i - 1] == 1)
            dp[0][i] = min(dp[0][i], dp[0][i - 1] + 1);
    }
    // for (int i = 1; i <= n; i++)
    //     cout << dp[0][i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << dp[1][i] << ' ';
    // cout << endl;
    int ans = min(dp[0][n], dp[1][n]);
    cout << (ans > n ? -1 : ans) << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _; // 单测记得注释这里喵
    while (_--)
        Thirstarfish();
    return 0;
}

/*
騒がしい日々に笑えない君に
思い付く限り眩しい明日を
*/
