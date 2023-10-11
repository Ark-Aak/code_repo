#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 100050
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
typedef pair<ll,ll> P;
priority_queue<P,vector<P>,greater<P> > q;
ll dis[Nx<<1],vis[Nx<<1],n;
ll h[Nx<<1],nxt[Nx<<3],to[Nx<<3],w[Nx<<3],tot;
inline void add(ll u,ll v,ll d){
	nxt[++tot]=h[u],h[u]=tot,to[tot]=v,w[tot]=d;
	nxt[++tot]=h[v],h[v]=tot,to[tot]=u,w[tot]=d;
}
inline ll Dijkstra(ll t,ll s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	while(q.size()) q.pop();
	q.push(make_pair(0,s));
	while(q.size()){
		ll u=q.top().second;q.pop();
		if(vis[u]) continue; 
		vis[u]=1;
		if(u==t) break;
		for(ll v,i=h[u];i&&(v=to[i]);i=nxt[i])
			if(dis[u]+w[i]<dis[v]) dis[v]=dis[u]+w[i],q.push(make_pair(dis[v],v));
	}
	return dis[t];
}
int main()
{
	freopen("double.in","r",stdin);
	freopen("double.out","w",stdout);
	rep(i,1,n=read()) add(i*2-1,i*2,read());
	rep(i,1,n-1){
		ll x=read(),y=read(),w1=read(),w2=read();
		add(x*2-1,y*2-1,w1);
		add(x*2,y*2,w2);
	}
	rep(i,1,read()) printf("%lld\n",Dijkstra(read(),read()));
	return 0;
}
