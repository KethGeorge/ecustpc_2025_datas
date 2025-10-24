#include <bits/stdc++.h>
#define fp(i, x, y) for(int i = (x); i <= (y); ++ i) 
#define fq(i, x, y) for(int i = (y); i >= (x); -- i) 
#define int long long
using namespace std;
const int N = 5e5 + 10, inf = 1e9;
struct node { 
  int a[11][11]; 
  friend node operator *(const node &A, const node &B) { 
    node C; memset(C.a, 0, sizeof(C.a)); 
    fp(i, 0, 10) fp(j, 0, 10) fp(k, 0, 10) 
     C.a[i][j] += A.a[i][k] * B.a[k][j]; 
    fp(i, 0, 10) fp(j, 0, 10) C.a[i][j] %= 9;
    return C;
  } 
  void clean() { 
    memset(a, 0, sizeof(a)); 
  } 
} S, E, I;    
node qpow(node x, int y) { 
  node z = I;
  for(; y; y >>= 1, x = x * x) 
    if(y & 1) z = x * z;
  return z;
}  
signed main() { 
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int T; cin >> T;
  fp(i, 0, 10) I.a[i][i] = 1;
  fp(i, 0, 9) { 
    int x = (i * i) / 10, y = (i * i) % 10; 
    E.a[i][x] ++; E.a[i][y] ++;
    E.a[i][10] = (x + y) % 9; 
  } 
  E.a[10][10] = 1;
  while(T --) { 
    int n, m;
    cin >> n >> m;
    S.clean(); 
    while(n) {
	  int c = n % 10; n /= 10;  
      S.a[0][c] ++; S.a[0][10] += c;
	} 
	S = S * qpow(E, m);
	cout << S.a[0][10] % 9 << '\n'; 
  } 
  return 0; 
} 
/*

2279
444981

*/