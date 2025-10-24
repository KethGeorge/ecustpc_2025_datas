#include <bits/stdc++.h> 
#define fp(i, x, y) for(int i = (x); i <= (y); ++ i) 
#define fq(i, x, y) for(int i = (y); i >= (x); -- i) 
#define fb(i, x) for(int i = head[x]; i != -1; i = nxt[i])
#define int long long 
#define ls k << 1
#define rs k << 1 | 1
using namespace std;
const int N = 4e5 + 10;
int n, m, a[N], b[N];
int solve() { 
  fp(i, 1, n) b[i] = a[i];
  sort(b + 1, b + 1 + n); 
  int sum = 0, now = 0, ans = 0;
  fp(i, 1, n) now += b[i], sum += b[i] * i - now;
  if(n % 2 == 0) { 
    fp(i, 1, n) { 
      if(i <= n / 2) { 
        if(i == n / 2) ans -= b[i];
        else ans -= 2 * b[i]; 
	  } else { 
	    if(i == n / 2 + 1) ans += b[i];
	    else ans += 2 * b[i];
	  } 
	} 
	sum -= ans;
  } else { 
    int a1 = 0, a2 = 0;
    fp(i, 1, n) { 
      if(i < n / 2) { 
        a1 -= 2 * b[i];
        a2 -= 2 * b[i];
	  } else if(i == n / 2) { 
	    a1 -= b[i];
	    a2 -= 2 * b[i];
	  } else if(i == n / 2 + 1) { 
	    a1 -= b[i];
	    a2 += b[i];
	  } else if(i == n / 2 + 2) { 
	    a1 += 2 * b[i];
	    a2 += b[i];
	  } else { 
	    a1 += 2 * b[i];
	    a2 += 2 * b[i];
	  } 
	} 
	sum -= max(a1, a2);
  } 
  return sum;
} 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T; cin >> T;
  while(T --) { 
    cin >> n >> m; 
    fp(i, 1, n) cin >> a[i];
    while(m --) { 
      int x, y;
      cin >> x >> y;
      a[x] += y;
      cout << solve() << '\n';
	}  
  } 
}  