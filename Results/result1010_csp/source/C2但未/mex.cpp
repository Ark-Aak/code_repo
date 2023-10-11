#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<1)+(x<<3)+s-48;s=getchar();}
	return x*f;
}
int n;
int b[20];
int f[20];
int vis[20];
int ans=0;
void dfs(int x){
	if(x==n+1){
		int s=0;
		while(vis[s])s++;
		ans=(ans+s);
		return;
	}
	for(int i=0;i<=b[x];i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)b[i]=read();
	dfs(1);
	printf("%d",ans);
	return 0;
}

