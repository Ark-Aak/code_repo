#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5,mod=1e9+7;
ll n,m,k,h[N],w[N];
ll ans,x,y,e[N],v[N];
char s;
int main() {
	freopen("wisdom.in", "r", stdin);
	freopen("wisdom.out", "w", stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
//	ans=(1+n*m%mod)*n*m%mod*500000004%mod;
	for(int i=1;i<=n;i++) {
//		h[i]=(((i-1)*m+1+m)%mod*m%mod*500000004%mod)%mod;
		e[i]=1;
	}
	for(int i=1;i<=m;i++) {
//		w[i]=((i*2%mod+m*(n-1)%mod)*n%mod*500000004)%mod;
		v[i]=1;
	}
	while(k--) {
		scanf("%s%lld%lld",&s,&x,&y);
		if(s=='R') {
			e[x]=e[x]*y%mod;
		} else {
			v[x]=v[x]*y%mod;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++)
			ans=(ans+(m*(i-1)+j)%mod*e[i]*v[j]%mod);
	}
	printf("%lld",ans);
	return 0;
}
/*

i:1-->n
j:1-->m
u[i][j]=(m*(i-1)+j)*e[i]*v[j]
	   =m*(i-1)*e[i]*v[j]+e[i]*v[j]*j
	   =i*m*e[i]*v[j]-m*e[i]*v[j]+e[i]*v[j]*j
	   =...so,???
*/
