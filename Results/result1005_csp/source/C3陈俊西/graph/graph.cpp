#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e3+5; 
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,Q;
int head[N],to[N<<1],nxt[N<<1],tot,cnt;
bool vis[N],cut[N];
void add(int u,int v){to[++tot]=v,nxt[tot]=head[u],head[u]=tot;}
bool dfs(int u,int t){
	if(u==t){
		cut[u]=1;
		return 1;
	}
	int res=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!vis[v]){
			vis[v]=1;
			res|=dfs(v,t);
			vis[v]=0;	
		}  
	}
	cut[u]|=res;
	return res;
}
void dfs2(int u){
	cut[u]=1,cnt++;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!cut[v])
			dfs2(v);
	}	
	return;
}
signed main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	Q=read();
	while(Q--){
		memset(vis,0,sizeof vis);
		memset(cut,0,sizeof cut); 
		int u=read(),v=read();
		vis[u]=1;		
		dfs(u,v);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(!cut[i]){
				cnt=0;
				dfs2(i);
				ans^=cnt;
			}
		} 
		printf("%lld\n",ans);
	}
	return 0;
}
/*
7 8
6 5
7 6
1 7
1 5
4 3
1 4
1 3
1 2
5
4 5
1 4
2 4
2 7
7 1
*/ 
