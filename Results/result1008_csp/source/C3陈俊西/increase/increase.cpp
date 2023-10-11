#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m;
int head[N],nxt[N<<1],to[N<<1],val[N<<1],tot;
void add(int u,int v,int w){to[++tot]=v,nxt[tot]=head[u],head[u]=tot,val[tot]=w;}
int dfs(int u,int mx,int sum,int AB){
	bool can=0;
	if(AB==0){//Alice
		int maxn=0;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i],w=val[i];
			if(w<=mx) continue;
			can=1;
			maxn=max(maxn,dfs(v,w,sum+1,AB^1));
		}	
		if(!can) return sum;
		return maxn;
	}
	else{//Bob
		int minn=N;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i],w=val[i];
			if(w<=mx) continue;
			can=1;
			minn=min(minn,dfs(v,w,sum+1,AB^1));
		}		
		if(!can) return sum;
		return minn;
	}
}
signed main(){
//	fc C:\Users\HP\Desktop\T\increase3.out C:\Users\HP\Desktop\T\increase3.ans
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}	
	for(int i=1;i<=n;i++)
		printf("%lld ",dfs(i,0,0,0));
	return 0; 
}
/*
4 6
3 1 2
2 3 1
4 1 5
1 4 3
2 1 6
1 3 4
*/
