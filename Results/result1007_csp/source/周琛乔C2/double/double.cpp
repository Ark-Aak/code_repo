#include<bits/stdc++.h>
#define int long long
#define P pair<int,int>
using namespace std;
const int N=2005;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
}
int head[N],to[N*6],nxt[N*6],tot,w[N*6];
inline void add(int x,int y,int v){
	to[++tot]=y;
	w[tot]=v;
	nxt[tot]=head[x];
	head[x]=tot;
}
inline void adde(int x,int y,int v){
	add(x,y,v);
	add(y,x,v);
}
int n,q,u,v;
vector<int> G[N];
int dis[N],k;
inline int Dj(int s,int t){
	memset(dis,-1,sizeof(dis));
	priority_queue<P,vector<P>,greater<P> >hp;
	hp.push({0,s});dis[s]=0;
	while(!hp.empty()){
		u=hp.top().second;
		hp.pop();
		if(u==t) return dis[t];
		for(int o=head[u];o;o=nxt[o]){
			if(dis[to[o]]==-1||dis[to[o]]>dis[u]+w[o]){
				dis[to[o]]=dis[u]+w[o];
				hp.push({dis[to[o]],to[o]});
			}
		}
	}return 114;
}
signed main(){
	freopen("double.in","r",stdin);
	freopen("double.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(k),adde(2*i-1,2*i,k);
	for(int i=1;i<n;i++){
		read(u),read(v);
		read(k);adde(2*u-1,2*v-1,k);
		read(k);adde(2*u,2*v,k);
	}
	read(q);
	while(q--){
		read(u),read(v);
		printf("%lld\n",Dj(u,v));
	}
	return 0;
}

