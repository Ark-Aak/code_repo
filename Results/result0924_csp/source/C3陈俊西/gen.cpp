#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,mod=1e9+7;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,deg[N],t[N],maxn;
map<pair<int,int>,int> mp;
int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}
signed main(){
	freopen("gen.in","r",stdin);
	freopen("gen.out","w",stdout);
	n=read(),m=read();
	mp.clear();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		deg[u]++,deg[v]++;
		maxn=max(maxn,max(deg[u],deg[v]));
	}
	if(n<=2000){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int x=deg[i],y=deg[j];
				ans=(ans+((x^y)*(x|y)*(x&y)))%mod;				
			}			
		}
		ans=ans*ksm(2,mod-2)%mod;
		printf("%lld",ans);
	}
	else if(maxn<=2000){
		int ans=0;
		for(int i=1;i<=n;i++)
			t[deg[i]]++;
		for(int i=0;i<=maxn;i++)
			for(int j=0;j<=maxn;j++)
				ans=(ans+(((i^j)*(i|j)*(i&j)))*(t[i]*t[j])%mod)%mod;
		ans=ans*ksm(2,mod-2)%mod;
		printf("%lld",ans);
	}
	return 0;
}
