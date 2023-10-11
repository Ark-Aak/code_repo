#include<bits/stdc++.h>
#define int long long
#define fi first
#define sd second
using namespace std;
const int N=1e3+5,K=55,M=1e6+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,k;
int head[M],nxt[M<<1],to[M<<1],val[M<<1],tot;
void add(int u,int v,int w){to[++tot]=v,nxt[tot]=head[u],head[u]=tot,val[tot]=w;}
int s[K][N],tp[K],dis[N];
bool vis[N];
void dij(){
	memset(dis,0x3f3f,sizeof dis);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;
	vis[1]=1;
	dis[1]=0;
	Q.push({0,1});
	while(!Q.empty()){
		int u=Q.top().sd;
		Q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i],w=val[i];
			if(!vis[v]&&dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				vis[v]=1;
				Q.push({dis[v],v});
			}
		}
	}
	return;
}
signed main(){
//	fc C:\Users\HP\Desktop\T\ex_tower1.out C:\Users\HP\Desktop\T\ex_tower1.ans
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		int col=read();
		s[col][++tp[col]]=i;
	}
	for(int i=1;i<=k;i++){
		string c;
		cin>>c;
		c=' '+c;
		for(int j=1;j<=k;j++){
			if(c[j]=='1'){
				for(int u=1;u<=tp[i];u++){
					for(int v=1;v<=tp[j];v++){
						int U=s[i][u],V=s[j][v];
						if(U==V) continue;
						add(U,V,abs(V-U));
						add(V,U,abs(V-U));
					}
				}
			}			
		}
	}
	dij();
	if(dis[n]==dis[0]) printf("-1");
	else printf("%lld",dis[n]);
	return 0; 
}
