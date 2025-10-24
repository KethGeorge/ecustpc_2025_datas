#include <bits/stdc++.h>
#define fp(i, x, y) for(int i = (x); i <= (y); ++ i) 
#define fq(i, x, y) for(int i = (y); i >= (x); -- i) 
#define int long long
using namespace std;
const int N = 5e5 + 10, inf = 1e9;
int n, a[N], f[N], g[N]; 
string s[50], t = "ECUST";
signed main() { 
  ios::sync_with_stdio(false); 
  cin.tie(0);
  fp(i, 0, 31) { 
    s[i] = t; 
    fp(j, 0, 4) if((i >> j) & 1) s[i][j] = s[i][j] - 'A' + 'a'; 
  } 
  sort(s, s + 32); 
  fp(i, 0, 31) cout << s[i] << '\n'; 
  return 0; 
} 
/*

1
6
1 1 1 1 1 1

*/