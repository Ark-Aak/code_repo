#include <bits/stdc++.h>
#define ll long long
using namespace std;

namespace IO{
	template<typename T>
	inline void qread(T &x){
		x=0;char ch;bool f=0;
		while((ch=getchar())&&(ch<'0'||ch>'9')) if(ch=='-') f=1;x=(ch^48);
		while((ch=getchar())&&(ch>='0'&&ch<='9')) x=(x<<1)+(x<<3)+(ch^48);
		x=f?-x:x;
	} 
	template<typename T>
	inline void write(T x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
}
using namespace IO;

const ll Maxn=5.2e5+7;
ll n;
vector<ll>e[Maxn];
ll f[Maxn],g[Maxn],ans[Maxn];
ll sz[Maxn],fa[Maxn];
void DFS1(ll u,ll ft){
	sz[u]=1;fa[u]=ft;
	for(ll v:e[u]) if(v!=ft) DFS1(v,u),sz[u]+=sz[v];
}
void DFS2(ll u){
	f[u]=(sz[u]*(sz[u]-1))/2;
	for(ll v:e[u])
		if(v!=fa[u]){
			DFS2(v);
			f[u]-=g[v];
			g[u]+=g[v];
		}
	g[u]+=f[u];
}
inline void Rvs(ll u,ll v){
	// 更新 szu,szv,fu,fv,gu,gv,fau,fav
	// 将 v 翻转到 u 上面，u 是当前的根 
	ll lstu=f[u],lstv=f[v];
	sz[u]=sz[u]-sz[v];
	sz[v]=sz[v]+sz[u];
	fa[u]=v;
	fa[v]=0;
	ll Sum1=f[u]+f[v];
	g[u]=g[u]-g[v];
	g[v]=g[v]+g[u];
	f[u]=(sz[u]*(sz[u]-1))/2-g[u]+f[u];
	f[v]=Sum1-f[u];
	ans[v]=ans[u]-lstu*u-lstv*v+u*f[u]+v*f[v];
}
void DFS3(ll u,ll ft){
	for(auto v:e[u]){
		if(v==ft) continue;
		ll lstu=f[u],lstv=f[v],szu=sz[u],szv=sz[v],fau=fa[u],fav=fa[v],gu=g[u],gv=g[v];
		Rvs(u,v);
		DFS3(v,u);
		f[u]=lstu,f[v]=lstv,sz[u]=szu,sz[v]=szv,fa[u]=fau,fa[v]=fav,g[u]=gu,g[v]=gv;
	}
}
int main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	qread(n);
	for(ll i=1,u,v;i<n;i++)
		qread(u),qread(v),
		e[u].push_back(v),
		e[v].push_back(u);
	DFS1(1,0);
	DFS2(1);
	for(ll j=1;j<=n;j++) ans[1]+=(f[j]*j);
	DFS3(1,0);
	for(ll i=1;i<=n;i++) write(2*ans[i]+n*(n+1)/2),putchar(' ');
	return 0;
}
/*
5
1 2
1 3
2 4
2 5
*/

