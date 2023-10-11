#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 50050
#define fi first
#define se second
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
ll N,K,b[Nx],last[Nx];
typedef pair<ll,ll> pii;
vector<ll> G[Nx];
char S[55][55];
ll dis[Nx],vis[Nx];
priority_queue<pii,vector<pii>,greater<pii> > q;
void build(ll s,ll t){
	memset(last,0,sizeof(last));
	for(ll i=s;i!=t;i+=(t-s)/abs(t-s)){
		rep(j,1,K) 
			if(S[b[i]][j]=='1'&&last[j]) 
				G[i].push_back(last[j]);
		last[b[i]]=i;
	}
}
ll Dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push(make_pair(0,1));
	while(q.size()){
		ll u=q.top().se;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(u==N) break;
		for(auto v:G[u]){
			if(dis[u]+abs(v-u)<dis[v]){
				dis[v]=dis[u]+abs(v-u);
				q.push(make_pair(dis[v],v));
			}
		}
	}
	return dis[N];
}
int main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	N=read(),K=read();
	rep(i,1,N) b[i]=read();
	rep(i,1,K) scanf("%s",S[i]+1);
	build(1,N+1),build(N,0);
	printf("%lld",Dijkstra());
	return 0;
}
