#include<bits/stdc++.h>
#define int long long
using namespace std;
int _,n,i,p,q,x,y,s[100001],w[100001];
vector<int>v[100001];
int dfs(int x,int f){
	s[x]=1;
	for(int i:v[x])if(i!=f){
		int c=dfs(i,x);
		s[x]+=s[i];
		if(c)return c;
	}
	if(w[x]!=w[f]-(s[x]-1)+(n-1-s[x]))return x;
	return 0;
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++)v[i].clear();
		for(i=1;i<n;i++)cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
		for(i=1;i<=n;i++)cin>>w[i];
		p=dfs(1,0);
		q=dfs(p,0);
		if(p == 0 && q == 0) p = 1, q = 2;
		cout<<p<<" "<<q<<endl;
	}
}