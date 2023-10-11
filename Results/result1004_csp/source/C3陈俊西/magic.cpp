#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,ans,c[1005],p[1005][10];
bool dis[1005][1005];
bool vis[1005];
void dfs(int id,int sum){
	if(id==n+1){
		int u=1,Sum=1;
		for(int i=1;i<=2*n;i++) vis[i]=0;
		int s=0;
		while(u!=1&&s){
			vis[u]=1;
			s++;
			for(int j=1;j<=2*n;j++)
				if(dis[u][j]&&!vis[j]){
					u=j,Sum++;
					vis[j]=1;
					break;
				} 
		}
		if(Sum==2*n) ans=min(ans,sum);
		return;
	}
	int a=p[id][1],b=p[id][2],cc=p[id][3],d=p[id][4];
	dis[a][b]=1;
	dis[b][a]=1;
	dis[cc][d]=1;
	dis[d][cc]=1;
	dfs(id+1,sum);
	dis[a][b]=0;
	dis[b][a]=0;
	dis[cc][d]=0;
	dis[d][cc]=0;		
	
	dis[a][cc]=1;
	dis[cc][a]=1;
	dis[b][d]=1;
	dis[d][b]=1;
	dfs(id+1,sum+c[id]);
	dis[a][cc]=0;
	dis[cc][a]=0;
	dis[b][d]=0;
	dis[d][b]=0;
	
	dis[a][d]=1;
	dis[d][a]=1;
	dis[cc][b]=1;
	dis[b][cc]=1;
	dfs(id+1,sum+c[id]);
	dis[a][d]=0;
	dis[d][a]=0;
	dis[cc][b]=0;
	dis[b][cc]=0;
	return;
}
signed main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read(),ans=1e12;
	for(int i=1;i<=n;i++){
		c[i]=read();
		for(int j=1;j<=4;j++)
			p[i][j]=read();
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
