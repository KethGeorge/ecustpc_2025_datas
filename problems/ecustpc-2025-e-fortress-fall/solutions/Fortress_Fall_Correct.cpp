#include <bits/stdc++.h>
#define fp(i, x, y) for(int i = (x); i <= (y); ++ i) 
#define fq(i, x, y) for(int i = (y); i >= (x); -- i) 
#define fb(i, x) for(int i = head[x]; i != -1; i = nxt[i])
#define int long long 
#define ls k << 1
#define rs k << 1 | 1
using namespace std;
const int N = 1e5 + 10;
int b[2], a[N], n, sum[N];
signed main() { 
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T; cin >> T;
  while(T --) { 
    cin >> n >> b[0] >> b[1];
    fp(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    fp(i, 1, n) sum[i] = sum[i - 1] + a[i]; 
    int ans = 0;
    fp(i, 1, n / 2) { 
      int l = 1, r = n, now = 0;
      fp(j, 0, 1) 
        if(b[j] <= 0) now += b[j] * (sum[l + i - 1] - sum[l - 1]), l += i; 
	    else now += b[j] * (sum[r] - sum[r - i]), r -= i;
	  ans = max(ans, now); 
	  now = 0;
	  l = 1; r = n;
      fq(j, 0, 1) 
        if(b[j] <= 0) now += b[j] * (sum[l + i - 1] - sum[l - 1]), l += i; 
	    else now += b[j] * (sum[r] - sum[r - i]), r -= i;
	  ans = max(ans, now);
	} 
	cout << ans << '\n';
  } 
  return 0; 
} 