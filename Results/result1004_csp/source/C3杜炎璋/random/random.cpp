#include<bits/stdc++.h>
#define int long long 
using namespace std;
int q[505][505];
int inv[200005];
const int mod=998244353;
signed main(){
	//freopen("random2.in","r",stdin);
	//freopen("random2.out","w",stdout);
	inv[0]=1;
	for(int i=1;i<=200000;i++) inv[i]=(inv[i-1]*2)%mod;
	int n,sum=0,cnt=0,ans=0;
	cin>>n;
	cnt=(n*(n-1))/2;
	for(int i=1;i<=n;i++) {
		string s;
		cin>>s;
		for(int j=1;j<=n;j++) {
			if(s[j-1]=='1') q[i][j]++,sum++;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			for(int k=j+1;k<=n;k++) {
				if(q[j][i] || q[k][j] || q[i][k]) continue;
				int tot=3-q[i][j]-q[j][k]-q[k][i];
				ans=(ans+(inv[cnt-sum-tot]))%mod;
			}
		}
	}
	printf("%lld",ans%mod);
	return 0;
}

