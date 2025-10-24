#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, n, a1, d, m, k;
  cin >> T;
  while(T --) { 
    cin >> n >> a1 >> d >> m >> k;
    if(d <= k) { 
      cout << m + 1 << '\n';
	} else if(k == 0) { 
	  cout << n + m << '\n';
	} else { 
	  int t = (d - 1) / k ; 
	  cout << m + max(1, n - (m / t)) << '\n'; 
	} 
  } 
  return 0; 
} 