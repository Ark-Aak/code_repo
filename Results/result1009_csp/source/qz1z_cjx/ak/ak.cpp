#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 1000005
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
const ll inf=LONG_LONG_MAX;
ll n,k,a[Nx];
namespace solve_pts_1{
	ll siz[10050],sum[10050],tot,val[10050];
	ll dfs(ll P,ll opt){
		if(siz[P]==1) return sum[tot]-sum[P];
		ll res=opt?inf:0;
		rep(S,0,tot) {
			if((siz[S]!=k)||((S&P)!=S)) continue;
			rep(i,1,k-1) if(!(S&(S<<i))) continue;
			if(opt) res=min(res,dfs(P^S,opt^1));
			else res=max(res,dfs(P^S,opt^1));
		}
		return res;
	}
	ll lowbit(ll x){return x&(-x);}
	void solve(){
		tot=(1ll<<n)-1;
		rep(i,1,n) val[1ll<<(i-1)]=a[i];
		rep(S,1,tot){
			siz[S]=siz[S-lowbit(S)]+1;
			sum[S]=sum[S-lowbit(S)]+val[lowbit(S)];
		}
		printf("%lld",dfs(tot,1));
	}
}
namespace solve_pts_2{
	ll sum;
	void solve(){
		rep(i,1,n) sum+=a[i];
		sort(a+1,a+n+1);
		printf("%lld",sum-a[n/2+1]);
	}
}
int main()
{	
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	n=read(),k=read();
	rep(i,1,n) a[i]=read();
	if(k==1) {
		using namespace solve_pts_2; 
		return solve(),0;
	}
	if(n<=10) {
		using namespace solve_pts_1; 
		return solve(),0;
	}
	return 0;
}
