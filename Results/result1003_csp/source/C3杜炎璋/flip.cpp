#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int f[524289][15],ch[15];
signed main(){
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	int n,K,ans=0;
	scanf("%lld %lld",&n,&K);
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=(1<<(i*2-2)),ch[i-1]=cnt;
	f[cnt][0]=1;
	for(int w=1;w<=K;w++) 
	for(int i=0;i<(1<<(2*n-1));i++) {
		for(int j=1;j<2*n;j++) {
			for(int k=j;k<2*n;k+=2) {
				if(((i)&(ch[(k-j)/2]<<((j-1))))==(ch[(k-j)/2]<<(j-1))) {
					f[((i)^(ch[(k-j)/2]<<(j-1)))][w]=(f[((i)^(ch[(k-j)/2]<<(j-1)))][w]+f[i][w-1])%mod;	
				}
			}
		}
	}
	for(int i=0;i<(1<<(2*n-1));i++) ans=(ans+f[i][K])%mod;
	printf("%lld",ans);
	return 0;
}

