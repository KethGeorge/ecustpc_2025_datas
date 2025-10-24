# include <bits/stdc++.h>

int main() {
  using namespace std;
  auto const solve = [] {
    int n;
    cin >> n;
    vector<int> a(n + 2, 1);
    for (int i(1); i <= n; ++i) cin >> a[i];
    for (int i(1); i <= n; ++i) assert(1 <= a[i] && a[i] <= n);
    vector<int> f(n + 2, n + 1);
    vector<int> g(n + 2, n + 1);
    g[n + 1] = f[0] = 0;
    for (int i(1); i <= n; ++i)
      if (a[i] > n - i + 1) break;
      else if (a[i - 1] - a[i] == 1) f[i] = f[i - 1];
      else if (a[i - 1] == 1) f[i] = f[i - 1] + 1;
      else break;
    for (int i(n); i >= 1; --i)
      if (a[i] > i - 1 + 1) break;
      else if (a[i + 1] - a[i] == 1) g[i] = g[i + 1];
      else if (a[i + 1] == 1) g[i] = g[i + 1] + 1;
      else break;
    int ans(n + 1);
    for (int i(0); i <= n; ++i)
      if (a[i] == 1 || a[i + 1] == 1)
        ans = min(ans, f[i] + g[i + 1]);
    cout << (ans <= n ? ans : -1) << endl;
  };
  int t;
  cin >> t;
  for (int i(1); i <= t; ++i)
    solve();
}