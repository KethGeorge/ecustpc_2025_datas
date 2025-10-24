#include<bits/stdc++.h>
#define int long long
using namespace std;
int _,r,i,j,p,t,k,u,v,c[400005],d[400005];
char s[10];
struct point{
	int x,y;
	point operator -(point u){
		return{x-u.x,y-u.y};
	}
}a[400005],b[600005];
double sqr(double x){
	return x*x;
}
int query(int l,int r){
	if(l>r)return 0;
	int m=(l+r)/2;
	cout<<"? 0 "<<m<<endl;
	cin>>s;
	if(s[0]=='I')return max(m,query(m+1,r));
	return query(l,m-1);
}
long long dot(point x,point y){
	return x.x*y.x+x.y*y.y;
}
int check(int x,int y){
	return dot(a[x]-b[y],(point){-b[y].y,b[y].x}-b[y])>=0&&dot(a[x]-b[y],(point){b[y].y,-b[y].x}-b[y])>=0;
}
int once(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>s;
	if(s[0]=='I'){
		cout<<"! Kevin"<<endl;
		return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>_;
	while(_--){
		r=query(1,200000);
		t=k=0;
		if(r==1){
			cout<<"? 1 1"<<endl;
			cin>>s;
			if(s[0]=='I')if(once(1,2)||once(2,1))goto br;
			cout<<"! NotConfirm"<<endl;
			goto br;
		}
		if(r==2){
			if(once(1,3)||once(3,1)||once(3,2)||once(2,3))goto br;
			cout<<"? 2 2"<<endl;
			cin>>s;
			if(s[0]=='I')cout<<"! NotConfirm"<<endl;else cout<<"! Bumper"<<endl;
			goto br;
		}
		for(i=1;i<=(r+1)/sqrt(2.)+0.99999;i++)p=sqrt((r+1)*(r+1)-i*i)+0.99999,a[++k]={i,p};
		for(i=1;i<=r;i++)p=(int)(sqrt(sqr(r)/2-sqr(r/2.-i))+r/2.+0.99999),b[++t]={i,p};
		u=1;v=0;
		for(i=1;i<=k;i++){
			while(v<t&&check(i,v+1))v++;
			while(u<=v&&!check(i,u))u++;
			c[i]=u,d[i]=v;
		}
		for(i=1,j=1;i<=t;i=d[j]+1){
			while(j<k&&c[j+1]<=i)j++;
			if(once(a[j].x,a[j].y)||once(a[j].y,a[j].x))goto br;
		}
		if(r==4)cout<<"? "<<(int)sqrt(r*r/2)<<" "<<(int)sqrt(r*r/2)+1<<endl;
		else cout<<"? "<<(int)sqrt(r*r/2)<<" "<<(int)sqrt(r*r/2)<<endl;
		cin>>s;
		if(s[0]=='I')cout<<"! Bumper"<<endl;else cout<<"! Kevin"<<endl;
		br:;
		cin>>s;
		assert(s[0]=='C');
	}
}