#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 10050
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
ll n,q;
struct point {
	ll x,y;
	bool operator<(const point a) const{ return this->y < a.y; }
} p[Nx];
void solve(ll L,ll D,ll R,ll U){
	ll past=0,mx=0,ans=0,last=0;
	drp(i,n,1){
		if(p[i].y>R||p[i].y<L||p[i].x<D||p[i].x>U) continue;
		if(last!=p[i].y) past=mx;
		if(p[i].x>=past) ans++;
		mx=max(mx,p[i].x),last=p[i].y;
	}
	printf("%lld\n",ans);
}
#define ONLINE_JUDGE//
#define DEBUG//
int main()
{
	#ifdef ONLINE_JUDGE
		freopen("ds.in","r",stdin);
		freopen("ds.out","w",stdout);
	#endif
	n=read(),q=read();
	rep(i,1,n) p[i].x=read();
	rep(i,1,n) p[i].y=read();
	sort(p+1,p+n+1);
	rep(i,1,q) solve(read(),read(),read(),read());
	return 0;
}
