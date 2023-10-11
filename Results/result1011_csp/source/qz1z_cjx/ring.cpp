#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 15
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
ll N,M,a[Nx],b[Nx],ans;
void check(){
	ll c[Nx],d[Nx];
	memcpy(c,a,sizeof a);
	memcpy(d,b,sizeof d);
	rep(i,1,N){
		ll x=d[i];
		ll A=x==1?N:x-1;
		ll B=x==N?1:x+1;
		if(c[A]>c[B]) swap(A,B);
		if(c[A]<i&&i<c[B]) return ans=(ans+1)%M,void();
		d[c[A]]=B,d[c[B]]=A,swap(c[A],c[B]);
	}
}
void dfs(ll x){
	if(x>N) {
		check();
		return ;
	}
	rep(i,1,N){
		if(!b[i]){
			a[x]=i;
			b[i]=x;
			dfs(x+1);
			b[i]=0;
		}
	}
}
#define ONLINE_JUDGE//
#define DEBUG//
int main()
{
	#ifdef ONLINE_JUDGE
		freopen("ring.in","r",stdin);
		freopen("ring.out","w",stdout);
	#endif
	N=read(),M=read();
	dfs(1);
	printf("%lld",ans);
	return 0;
}
