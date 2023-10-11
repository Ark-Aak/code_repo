#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
const int Maxn=5e4+55+5;
int n,k;
int b[Maxn];
int f[Maxn][55],g[Maxn],fg[55][Maxn][2];//0:< 1:>
int e[55][55];
vector<int>c[55];
long long cnt=0;
int vis[Maxn];
int vv[Maxn];
int dfs(int u,int s){
	if(f[u][s]<1e9)return f[u][s];
	if(!e[s][b[u]])return f[u][s]=-1;
	vis[u]=1;
	cnt++;
	if(!vv[s]){
		//printf("%d\n",s);
		//if(n>5000)vv[s]=1;
		for(int i=0;i<c[s].size();i++){
			++cnt;
			int y=c[s][i];
			if(y==u)continue;
			int op=1;
			if(g[y]>1e9)
				for(int j=1;j<=k;j++){
					if(vis[y]==0&&dfs(y,j)!=-1){
						g[y]=min(g[y],f[y][j]),cnt++;
						if(vv[s]){
							op=0;break;
						}
					}
				}
			if(!op)break;
			if(g[y]>1e9)g[y]=-1;
			if(g[y]==-1&&i)fg[s][y][0]=fg[s][c[s][i-1]][0];
			if(g[y]==-1)continue;
			if(!i)fg[s][y][0]=g[y]-y;
			else fg[s][y][0]=min(fg[s][c[s][i-1]][0],g[y]-y);
			//printf("%d %d\n",g[y],y);
		}
		if(!vv[s]){
			for(int i=c[s].size()-1;~i;i--){
				++cnt;
				int y=c[s][i];
				if(g[y]==-1&&i<c[s].size()-1)fg[s][y][1]=fg[s][c[s][i+1]][1];
				if(g[y]==-1)continue;
				if(i==c[s].size()-1)fg[s][y][1]=g[y]+y;
				else fg[s][y][1]=min(fg[s][c[s][i+1]][1],g[y]+y);
			}
			int data=-114514;
			cnt+=2*n;
			for(int y=1;y<=n;y++){
				if(fg[s][y][0]<1e9){
					if(data==-114514)data=fg[s][y][0];
					else data=min(data,fg[s][y][0]);
				}
				fg[s][y][0]=data;
			}//printf("%d\n",data);
			data=-114514;
			for(int y=n;y;y--){
				if(fg[s][y][1]<1e9){
					if(data==-114514)data=fg[s][y][1];
					else data=min(data,fg[s][y][1]);
				}
				fg[s][y][1]=data;
			}
		}
	}
	vis[u]=0;vv[s]=1;
	if(fg[s][u][0]!=-114514)f[u][s]=fg[s][u][0]+u;
	if(fg[s][u][1]!=-114514)f[u][s]=min(f[u][s],fg[s][u][1]-u);
	if(f[u][s]>1e9)f[u][s]=-1;
	//printf("%d %d %d %d\n",cnt,u,s,f[u][s]);
	return f[u][s];
}
namespace Solve40{
	const int Maxn=5e4+55+5;
	int n,k;
	int b[Maxn];
	int head[Maxn],nxt[Maxn<<2],to[Maxn<<2],cnt1;
	inline void add(int u,int v){
		to[++cnt1]=v;
		nxt[cnt1]=head[u];
		head[u]=cnt1;
	}
	int f[Maxn];
	struct node{
		int u,data;
		inline bool operator<(const node&a)const{
			return a.data<data;
		}
	};
	priority_queue<node>heap;
	vector<int>e[55];
	int vis[Maxn];
	inline void solve40(){
		for(int i=1;i<=n;i++){
			read(b[i]);
			add(b[i],i);
		}
		for(int i=1;i<=k;i++)
			for(int j=1;j<=k;j++){
				int d;scanf("%1d",&d);
				if(d)e[i].push_back(j);
			}
		memset(f,0x7f,sizeof f);
		f[1]=0;
		heap.push({1,0});
		while(heap.size()){
			node tmp=heap.top();
			heap.pop();
			int u=tmp.u;
			if(vis[u])continue;
			vis[u]=1;
			for(auto y:e[b[u]]){
				for(int j=head[y];j;j=nxt[j]){
					int v=to[j];
					if(u!=v&&f[v]>f[u]+abs(u-v)){
						f[v]=f[u]+abs(u-v);
						heap.push({v,f[v]});
					}
				}
			}
		}
		printf("%d\n",f[n]>=1e9?-1:f[n]);
	}
}
int main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	read(n);read(k);
	if(n<=50000){
		Solve40::n=n;
		Solve40::k=k;
		using namespace Solve40;
		solve40();
		return 0;
	}
	for(int i=1;i<=n;i++)read(b[i]),c[b[i]].push_back(i);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			scanf("%1d",&e[i][j]);
	memset(f,0x7f,sizeof f);
	memset(g,0x7f,sizeof g);
	memset(fg,0x7f,sizeof fg);
	for(int i=1;i<=k;i++)
		f[1][i]=0;
	int ans=1e9+5;
	for(int i=1;i<=k;i++)
		if(dfs(n,i)!=-1)ans=min(ans,f[n][i]);//,printf("%d %d %d\n",n,i,f[n][i]);
	printf("%d\n",ans>1e9?-1:ans);
	//printf("%d\n",cnt);
	return 0;
}

