#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5,inf=1e18;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,c,s[N][N],tp[N],val[N],dp[N][N];
signed main(){
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	n=read(),m=read(),c=read();
	for(int i=1;i<=n;i++) val[i]=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		s[v][++tp[v]]=u;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=1000;j++)
			dp[i][j]=-inf;
	dp[1][0]=0;
	for(int ct=1;ct<=1000;ct++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=tp[i];j++){
				int u=i,v=s[i][j];
				for(int T=0;T<1000;T++)
					dp[u][T+1]=max(dp[u][T+1],dp[v][T]+val[u]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=1000;i++)
		ans=max(ans,dp[1][i]-c*i*i);
	printf("%lld",ans);
	return 0;
}
