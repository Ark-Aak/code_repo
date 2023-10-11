#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20,mod=1e9+7;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,a[N],ans,vis[N];
void solve(int x){
	if(x==n+1){
		int mex=0;
		while(vis[mex]) mex++;
		ans=(ans+mex)%mod;
		return;
	}
	for(int i=0;i<=a[x];i++)
		vis[i]++,solve(x+1),vis[i]--;
	return;
}
signed main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	solve(1);
	printf("%lld",ans);
	return 0; 
}
