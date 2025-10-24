#include <bits/stdc++.h>
#define fp(i, x, y) for(int i = (x); i <= (y); ++ i) 
#define fq(i, x, y) for(int i = (y); i >= (x); -- i) 
#define int long long
using namespace std;
const int N = 5e5 + 10, inf = 1e9;
void print(int x) { 
  if(x < 10) cout << 0 << x ;
  else cout << x;
} 
signed main() { 
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int T; cin >> T;
  while(T --) { 
    int a, b; 
    cin >> a >> b;
    swap(a, b); 
    if(a <= 23 && b <= 59) { 
      print(a); cout << ":"; print(b); 
      cout << "  " << '\n'; 
	} else 
	if(b <= 23 && a <= 59) { 
	  print(b); cout << ":"; print(a); 
	  cout << "  " << '\n'; 
	} else cout << -1 << '\n'; 
  } 
  return 0; 
} 
/*

1
6
1 1 1 1 1 1

*/