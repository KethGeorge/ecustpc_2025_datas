#include <bits/stdc++.h>
#define fp(i, x, y) for(int i = (x); i <= (y); ++ i) 
#define fq(i, x, y) for(int i = (y); i >= (x); -- i) 
#define int long long
using namespace std;
const int N = 5e5 + 10, inf = 1e9;
int n, a[N], f[N], g[N]; 
int solve() { 
  f[0] = g[n + 1] = 0; 
  fp(i, 1, n) { 
    if(i == 1 || a[i - 1] == 1) f[i] = f[i - 1] + 1; 
    else if(a[i] == a[i - 1] - 1) f[i] = f[i - 1]; 
    else f[i] = inf; 
  } 
  fq(i, 1, n) { 
    if(i == n || a[i + 1] == 1) g[i] = g[i + 1] + 1;
	else if(a[i] == a[i + 1] - 1) g[i] = g[i + 1];
	else g[i] = inf; 
  } 
  int ans = inf;
  if(a[n] == 1) ans = min(ans, f[n]);
  if(a[1] == 1) ans = min(ans, g[1]); 
  fp(i, 1, n - 1) { 
    if(a[i + 1] == 1 && a[i] + i - 1 <= n) ans = min(ans, f[i] + g[i + 1]);  
    if(a[i] == 1 && 1 <= i + 2 - a[i + 1]) ans = min(ans, f[i] + g[i + 1]); 
  } 
  return (ans > n ? -1 : ans); 
} 
signed main() { 
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int T; cin >> T;
  while(T --) { 
    cin >> n;
    fp(i, 1, n) cin >> a[i];
    cout << solve() << '\n'; 
  }   
  return 0; 
} 
/*

1
6
1 1 1 1 1 1

*/