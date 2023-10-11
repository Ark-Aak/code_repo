#include<bits/stdc++.h>
#define int long long
#define ll long long
#define mid ((l+r)>>1)
#define FOR(i,a,b) for(ll i=(a); i<=(b); ++i)
#define ROF(i,a,b) for(ll i=(a); i>=(b); --i)
#define modj(x) ((x)-=((x)>=MOD)?MOD:0)
#define qmin(x,y) ((x)=min((x),(y)))
#define qmax(x,y) ((x)=max((x),(y)))
using namespace std;
const int MAXN=1e5;
inline ll read(){
	ll t=0,f=0;char v=getchar();
	while(!isdigit(v))f|=(v=='-'),v=getchar();
	while(isdigit(v))t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
inline void write(ll x){
	if(x<0){x*=-1; putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
int n,k,maxx=1e16;
int a[MAXN],tot;
int f[MAXN],dep[MAXN];
vector<int>q[MAXN];
int p[MAXN];
void dfs(int x,int fa){
	f[x]=fa;
	dep[x]=dep[fa]+1;
	for(auto v:q[x]){
		if(v!=f[x])
			dfs(v,x);
	}
}
int Lca(int x,int y){
	while(x!=y){
		if(dep[x]>dep[y]) swap(x,y);
		y=f[y];
	}
	return y;
}
signed main(){
	freopen("loser.in","r",stdin);
	freopen("loser.out","w",stdout);
	int T=1;
	while(T--){
		n=read();k=read();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			q[u].push_back(v);
			q[v].push_back(u);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=k;i++){
			int op=read(),u=read(),v=read();
			int lca=Lca(u,v);
			if(op==1){
				while(u!=lca){
					a[u]=1-a[u];
					u=f[u];
				}
				while(v!=lca){
					a[v]=1-a[v];
					v=f[v];
				}
				a[lca]=1-a[lca];
			}
			else{
				tot=0;
				int jl=dep[u]-dep[lca]+1+dep[v]-dep[lca];
				while(u!=lca){
					p[++tot]=u;
					u=f[u];
				}
				p[++tot]=lca;
				while(v!=lca){
					p[jl--]=v;
					tot++;
					v=f[v];
				}
				int l=0,r=0;
				for(int j=1;j<=tot;j++){
					if(a[j]==0) l++;
					else if(r+1<=l){
						r++;
					}
				}
				printf("%lld\n",r*2);
			}
		}
	}
	return 0;
}
/*
5 4
1 4 2 3 4
1010
0001
0110
0100
*/

