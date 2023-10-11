#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 25
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
struct tim{
	ll x,type,id;
	bool operator<(tim a){ return this->x < a.x; }
} p[Nx<<1];
ll n,t,m,tot,ans,used[Nx];
inline void calc(){
	ll res=0;
	rep(i,2,tot){
		ll dx=p[i].x-p[i-1].x,id_1=p[i-1].id,id_2=p[i].id;
		if(p[i-1].type==1&&p[i].type==1) res+=dx*used[id_1];
		if(p[i-1].type==2&&p[i].type==2) res+=dx*used[id_2];
		if(p[i-1].type==1&&p[i].type==2) res+=dx*(used[id_1]&used[id_2]);
		if(p[i-1].type==2&&p[i].type==1) res+=dx;
	}
	ans=max(ans,res+p[1].x+t-p[tot].x);
}
inline void dfs(ll x,ll cnt){
	if(cnt==m) return (void)calc();
	if(x>n) return ;
	used[x]=1,dfs(x+1,cnt+1);
	used[x]=0,dfs(x+1,cnt);
}
int main()
{
	freopen("seal.in","r",stdin);
	freopen("seal.out","w",stdout);
	n=read(),t=read(),m=read();
	rep(i,1,n){
		p[++tot].x=read(),p[tot].type=1,p[tot].id=i;
		p[++tot].x=read(),p[tot].type=2,p[tot].id=i;
	}
	sort(p+1,p+tot+1);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
