#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int a[55][55],f[55][55];
signed main(){
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	int n,sum=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			char c;
			cin>>c;
			if(c=='L') a[i][j]=2;
			else if(c=='R') a[i][j]=1;
			else if(c=='D') a[i][j]=100;
			else if(c=='U') a[i][j]=102;	
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cin>>f[i][j];
		}
	}
	sum+=(a[1][1]+1==a[1][2])*(f[1][1]+f[1][2])%mod;
	sum+=(a[2][1]+1==a[2][2])*(f[2][1]+f[2][2])%mod;
	sum+=(a[1][1]+1==a[1][2] && a[2][1]+1==a[2][2])*(f[1][1]+f[1][2]+f[2][1]+f[2][2])%mod;
	sum+=(a[1][1]+2==a[2][1])*(f[1][1]+f[2][1])%mod;
	sum+=(a[1][2]+2==a[2][2])*(f[1][2]+f[2][2])%mod;
	sum+=(a[1][2]+2==a[2][2] && a[1][1]+2==a[2][1])*(f[1][2]+f[2][2]+f[2][1]+f[1][1])%mod;
	printf("%lld",sum%mod);
	return 0;
}

