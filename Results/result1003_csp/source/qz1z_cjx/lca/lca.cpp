#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 500500
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
void write(ll x){
	if(x/10) write(x/10);
	putchar((char)(x%10+'0'));
}
//---------------------------------//
ll n,f[Nx],siz[Nx],ans[Nx];
ll h[Nx],nxt[Nx<<1],to[Nx<<1],tot;
inline void add(ll u,ll v){
	nxt[++tot]=h[u],h[u]=tot,to[tot]=v;
	nxt[++tot]=h[v],h[v]=tot,to[tot]=u;
}
inline ll dfs1(ll u,ll fa){
	for(ll v,i=h[u];i&&(v=to[i]);i=nxt[i]) 
	if(v!=fa) f[u]+=dfs1(v,u)+siz[u]*siz[v]*2*u,siz[u]+=siz[v];
	siz[u]++;
	return f[u]=f[u]+(siz[u]*2-1)*u;
}
inline void dfs2(ll u,ll fa,ll res){
	ans[u]=res=(res+siz[u]*(siz[1]-siz[u])*2*u);
	for(ll v,i=h[u];i&&(v=to[i]);i=nxt[i])
	if(v!=fa) dfs2(v,u,res-siz[v]*(siz[1]-siz[v])*2*u);
}
int main()
{
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	rep(i,1,(n=read())-1) add(read(),read());
	dfs1(1,0),dfs2(1,0,f[1]);
	rep(i,1,n) write(ans[i]),putchar(' ');
	return 0;
 } 
