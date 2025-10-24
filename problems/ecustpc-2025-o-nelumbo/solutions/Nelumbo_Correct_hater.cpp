#include <bits/stdc++.h>
#define fp(i, x, y) for(int i = (x); i <= (y); ++ i) 
#define int long long
using namespace std;
const int mod = 998244353, N = 2e5 + 10; 
int pre[N], sz[N]; bool vis[N], is[N];
int qp(int x, int y) { 
  int z = 1;
  for(; y; y >>= 1, x = x * x % mod) 
    if(y & 1) z = x * z % mod;
  return z;
} 
vector <int> A, B, v[N], a[N];
int f(int x) { return pre[x] == x ? x : pre[x] = f(pre[x]); } 
int C(int x) { return x * (x - 1) / 2; } 
void merge(int x, int y) { 
  x = f(x); y = f(y); 
  if(x == y) return ;
  pre[x] = y; sz[y] += sz[x];
} 
int solve() { 
  int ans = 0;
  //cout << "A : " ; for(auto x : A) cout << x << ' '; cout << '\n';
 // cout << "B : " ; for(auto x : B) cout << x << ' '; cout << '\n';
  for(auto x : A) pre[x] = x, sz[x] = 1, is[x] = 1, vis[x] = 0; 
  for(auto x : A) for(auto y : v[x]) if(is[y]) merge(x, y);
  for(auto x : A) { 
    int fx = f(x);
    if(!vis[fx]) vis[fx] = 1, ans -= C(sz[fx]);
  } 
  for(auto x : A) vis[x] = 0;
  for(auto x : B) pre[x] = x, sz[x] = 1, is[x] = 1, vis[x] = 0;
  for(auto x : B) for(auto y : v[x]) if(is[y]) merge(x, y);//, cout << "M2 : " << x << ' ' << y << '\n';
  for(auto x : A) { 
    int fx = f(x); 
    if(!vis[fx]) vis[fx] = 1, ans += C(sz[fx]);//, cout << "F : " << sz[fx] << '\n';
  } 
  for(auto x : B) { 
    int fx = f(x);
    if(!vis[fx]) vis[fx] = 1, ans += C(sz[fx]);//, cout << "F : " << sz[fx] << '\n';
  } 
  for(auto x : A) pre[x] = x, sz[x] = 1, is[x] = vis[x] = 0;
  for(auto x : B) pre[x] = x, sz[x] = 1, is[x] = vis[x] = 0; 
  ans %= mod;
  return ans;
} 
signed main() { 
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T; cin >> T;
  while(T --) { 
    int n, x, y;
    cin >> n;
    fp(i, 1, n) v[i].clear(), a[i].clear(), pre[i] = i, sz[i] = 1, is[i] = vis[i] = 0;
    fp(i, 1, n - 1) { 
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x); 
	} 
	fp(i, 1, n) cin >> x, a[x].push_back(i);
	int ans = 0;
	fp(i, 1, n) { 
	  A.clear(); B.clear(); 
	  for(int j = 2 * i; j <= n; j += i) 
	    for(auto x : a[j]) A.push_back(x); 
	  for(auto x : a[i]) B.push_back(x); 
	  //cout << "Now : " << i << '\n';
	  ans += solve() * i % mod;
	  ans %= mod;
	} 
	cout << ans % mod * qp(C(n) % mod, mod - 2) % mod << '\n';
  }  
} 