#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int Maxn=1e6+5;
int n,q;
int head[Maxn],to[Maxn<<1],nxt[Maxn<<1],cnt1;
inline void add(int u,int v){
	to[++cnt1]=v;
	nxt[cnt1]=head[u];
	head[u]=cnt1;
}
int dep[Maxn],f[Maxn][24];
int a[Maxn][24];
void dfs(int u,int v){
	f[u][0]=v;
	dep[u]=dep[v]+1;
	for(int i=1;i<=23;i++){
		f[u][i]=f[f[u][i-1]][i-1];
		a[u][i]=min(a[u][i-1],a[f[u][i-1]][i-1]);
	}
	for(int i=head[u];i;i=nxt[i]){
		int y=to[i];
		if(y==v)continue;
		dfs(y,u);
	}
}
int ans=1e9;
inline int Lca(int u,int v){
	if(u==v)return u;
	if(dep[u]<dep[v])swap(u,v);
	for(int i=22;~i;i--)
		if(dep[f[u][i]]>=dep[v]){
			ans=min(ans,a[u][i]);
			u=f[u][i];
			
		}
	if(u==v)return u;
	for(int i=22;~i;i--)
		if(f[u][i]&&f[v][i]&&f[u][i]!=f[v][i]){
			ans=min(ans,a[u][i]);
			ans=min(ans,a[v][i]);
			u=f[u][i];
			v=f[v][i];
		}
	ans=min(ans,f[u][0]);
	return f[u][0];
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	memset(a,0x7f,sizeof a);
	n=read();q=read();
	for(int i=1;i<=n;i++)a[i][0]=i;
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	int lca=0;
	for(int i=1;i<=q;i++){
		char s[7];
		scanf("%s",s+1);
		int x=read();
		if(s[1]=='J'){
			if(!lca)lca=ans=x;
			else{
				ans=min(ans,x);
				lca=Lca(lca,x);
			}
		}
		else{
			int ans1=ans;
			ans=min(ans,x);
			int lca1=Lca(lca,x);
			printf("%d\n",ans);
			ans=ans1;
		}
	}
	return 0;
}

