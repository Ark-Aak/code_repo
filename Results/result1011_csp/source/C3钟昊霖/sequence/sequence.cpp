#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(int i=a;i<=b;i++)
inline int read();

const int N = 2e5+5,Mod=998244353;

int n,m,f[2][N],g[5005],sum,sum1;
inline void  mod(int & x) {
	if(x>Mod) x%=Mod;
	if(x<0ll) x=((x+Mod)%Mod+Mod);
}
signed main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read();
	for(int i=1; i<=m; i++) f[1][i]=1;
	sum=m;
	sum1=m;
	int o=1;
	for(int i=2; i<=n; i++) {
		sum=0;
		o^=1;
		for(int j=1; j<=m; j++) {
			f[o][j]=sum1;
			for(int k=2; k*j<=m; k++) if(k*j<=m)f[o][j]-=f[(o^1)][k*j];
				sum+=f[o][j];
			mod(f[o][j]);
			mod(sum);
		}
		sum1=sum;
	}
	int ans = 0;
	for(int i=1;i<=m;i++) ans+=f[o][i],mod(ans);
	cout<<ans;
	return 0;
}

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}


