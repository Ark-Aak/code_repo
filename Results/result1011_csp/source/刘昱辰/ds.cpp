#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll a[N],n,m,ans[N];
namespace MYINPUT{
	const int S=(1<<20)+5;char B[S],*H=B,*T=B;
	inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
	inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
struct qwq{
	ll x,y;
}f[N];
struct query{
	ll x1,x2,y1,y2,id;
	/*
	 y2
	_______
	|     |
x1	|     | x2
	|     |
	|_____|
	   y1
			*/
}q[N];
bool cmp(qwq a,qwq b){
	if(a.x==b.x)return a.y<b.y;
	return a.x>b.x; 
}
bool cmp1(query a,query b){
	return a.x2>b.x2; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("ds.in","r",stdin);
    freopen("ds.out","w",stdout);
    n=fr();
	m=fr(); 
    for(int i=1;i<=n;i++)f[i].x=fr();
    for(int i=1;i<=n;i++)f[i].y=fr();
	sort(f+1,f+n+1,cmp);
	for(int i=1;i<=m;q[i].id=i,i++){
		q[i].x2=fr();
		q[i].y2=fr();
		q[i].x1=fr();
		q[i].y1=fr();
	}
	sort(q+1,q+m+1,cmp1);
	ll tag=1;
	for(int i=1;i<=m;i++){
		while(q[i].x2<f[tag].x)tag++;
		ll mx=q[i].y1,cnt=0;
		for(int j=tag;j<=n;j++){
			if(f[j].x<q[i].x1)break;
			if(f[j].y<q[i].y1||f[j].y>q[i].y2)continue;
			if(f[j].y>=mx)cnt++,mx=f[j].y;
		}
		ans[q[i].id]=cnt;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
    return 0;
}
