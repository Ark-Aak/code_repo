#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500500,mod=998244353;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')
          f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)
	  write(x/10);
	putchar(x%10+'0');
}
ll n,m,s,t,s1,s2,cnt=0,sum=0,ans=0;
vector<ll> E[N],G[N];
ll dfn[N],low[N],scc[N],siz[N],d[N];
stack<ll> T;
set<pair<ll,ll>> S;
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1ll)
		  ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1ll;
	}
	return ans;
}
void add(ll u,ll v){
	E[u].push_back(v);
	E[v].push_back(u);
}
void Add(ll u,ll v){
	G[u].push_back(v);
	G[v].push_back(u);
	d[u]++,d[v]++;
}
void tarjan(ll u,ll fa){
	ll son=0;
	dfn[u]=low[u]=++cnt;
	T.push(u);
	for(auto v:E[u]){
		if(!dfn[v]){
			son++;
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				++sum;
				scc[u]=sum;
				while(T.top()!=v){
					scc[T.top()]=sum;
					T.pop();
				}
				scc[v]=sum;
				T.pop();
			}
		}
		else if(v!=fa)
		  low[u]=min(low[u],dfn[v]);
	}
	if(!son&&!fa){
		++sum;
		scc[u]=sum;
	}
}
int main(){
	n=read(),m=read(),s=read(),t=read();
	add(s,t);
	for(int u,v,i=1;i<=m;i++){
		u=read(),v=read();
		add(u,v);
	}
	tarjan(1,0);
	for(int i=1;i<=n;i++){
	    for(auto v:E[i]){
		    if(scc[i]!=scc[v]&&!S.count({scc[i],scc[v]})&&!S.count({scc[v],scc[i]})){
		    	Add(scc[i],scc[v]);
		    	S.insert({scc[i],scc[v]});
		    	S.insert({scc[v],scc[i]});
			}
		}
		siz[scc[i]]++;
	}
	for(int i=1;i<=sum;i++)
	  if(d[i]==1)
	    ans++;
	if(ans<3)
	  puts("1");
	else
	  puts("0");
	return 0;
}
