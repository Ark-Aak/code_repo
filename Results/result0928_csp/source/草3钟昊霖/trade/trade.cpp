#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define F(i,a,b) for(int i=a;i<=b;i++)
#define Debug(x) cerr<<"------------"<<x<<"---------------"<<endl;

const int N=8e5+5;

inline int read();

int T=1;

int head[N],to[N],nxt[N],w[N],a[N],dis[N],tot,ans=-INT_MAX;

bool vis[N];

int n,m,c;

inline void AddEdge(int u,int v,int w1){
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
	w[tot]=w1;
}

inline void zuiduanlu(){
	memset(dis,0x7f,sizeof dis);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> >  >Q;
	Q.push(make_pair(0,1));
	dis[1]=0;
	while(!Q.empty()){
		int t=Q.top().second;
		Q.pop();
		if(vis[t]) continue;
		else vis[t]=1;
		for(int i=head[t];i;i=nxt[i]){
			if(!vis[to[i]]&&dis[to[i]]>dis[t]+w[i]){
				dis[to[i]]=dis[t]+w[i];
				Q.push(make_pair(dis[to[i]],to[i]));
			}
		}
	}
	return;
} 


signed main(){
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	while(T--){
		n=read(),m=read(),c=read();
		F(i,1,n) a[i]=read();
		for(int i=1,u,v;i<=m;i++){
			u=read(),v=read();
			for(int j=1;j<=150;j++){
				AddEdge(u+(j-1)*n,v+j*n,-a[u]);
			}
		}
		zuiduanlu();
		for(int i=0;i<=150;i++){
			ans = max(-dis[1+i*n]-c*(i*i),ans);
		}
		cout<<ans;
	}
	return 0;
}

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
