#include <bits/stdc++.h>
#define fp(i, x, y) for(int i = (x); i <= (y); ++ i) 
using namespace std;
signed main() { 
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T; cin >> T;
  while(T --) { 
    int n; cin >> n;
    fp(i, 1, n) 
      cout << (1 << 29) + i << ' ';
    cout << '\n';
  } 
} 