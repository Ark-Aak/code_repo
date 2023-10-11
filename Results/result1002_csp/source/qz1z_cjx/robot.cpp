#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i++)
#define ll long long
#define Nx 120050
using namespace std;
//---------------------------------// 
ll read(){
    ll x=0,f=0;char ch;
    while(!isdigit(ch=getchar())) f|=ch=='-';
    while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return f?-x:x;
}
//---------------------------------//
ll n,m;
class workroom{
public :
	ll h[Nx],nxt[Nx<<1],to[Nx<<1],tot;
	ll RD[Nx];
	inline void add(ll u,ll v){
		nxt[++tot]=h[u],h[u]=tot,to[tot]=v;
	}
	inline void init(){
		memset(h,0,sizeof(h)),tot=0;
		memset(RD,0,sizeof(RD));
	}
	inline bool check(){
		rep(u,1,m) for(ll i=h[u];i;i=nxt[i])
			RD[to[i]]++;
		queue<ll> q;
		rep(i,1,m) if(!RD[i]) q.push(i);
		ll cnt=0;
		while(q.size()){
			ll u=q.front();q.pop();
			cnt++;
			for(ll i=h[u];i;i=nxt[i])
				if(--RD[to[i]]==0) q.push(to[i]);
		}
		return cnt==m;
	}
} Re;
namespace Studio{
	ll h[Nx],nxt[Nx<<1],to[Nx<<1],tot,q[Nx],p[Nx];
	ll _start[Nx],_end[Nx],f[Nx],vis[Nx],past[Nx];
	inline void init(){
		memset(h,0,sizeof(h)),tot=0;
		memset(vis,0,sizeof(vis));
		memset(_start,0,sizeof(_start));
		memset(_end,0,sizeof(_end));
		rep(i,1,n) f[i]=i;
	}	
	inline void add(ll u,ll v){
		nxt[++tot]=h[u],h[u]=tot,to[tot]=v;
		nxt[++tot]=h[v],h[v]=tot,to[tot]=u;
	}
	inline ll find(ll x){
		return f[x]==x?x:f[x]=find(f[x]);
	}
	inline void rebuild(ll x,ll id){
		if(_start[x]&&_start[x]!=id) Re.add(_start[x],id);
		if(_end[x]&&_end[x]!=id) Re.add(id,_end[x]);
	}
	inline void search(ll u,ll v,ll t,ll id){
		while(u&&u!=t) rebuild(u,id),u=past[u];
		while(v&&v!=t) rebuild(v,id),v=past[v];
		rebuild(t,id);
	}
	inline void Tarjan(ll u,ll fa){
		vis[u]=1,past[u]=fa;
		ll a=_start[u],b=_end[u];
		if(a&&vis[q[a]]) search(p[a],q[a],find(q[a]),a);
		else if(b&&vis[p[b]]) search(p[b],q[b],find(p[b]),b);
		for(ll i=h[u];i;i=nxt[i]) {
			ll v=to[i];
			if(v==fa) continue;
			Tarjan(v,u);
			f[v]=u;
		} 
	}
	inline void main(){
		rep(T,1,read()){
			n=read(),init(),Re.init();
			rep(i,1,n-1) add(read(),read());
			rep(i,1,m=read()) p[i]=read(),q[i]=read(),_start[p[i]]=i,_end[q[i]]=i;
			Tarjan(1,0);
			if(Re.check()) printf("Yes\n");
			else printf("No\n");
		}
	}
} //namespace Studio
int main()
{ 
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	Studio::main();
	return 0;
}
