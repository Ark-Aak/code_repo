#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int Mod=1e9+7;
int n,m;
int ans,gg;
signed main() {
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--){
		ans=0;
		scanf("%lld%lld",&n,&m);
		if(n==1||m==1){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				for(int i1=i;i1<n;i1++){
					for(int j1=j;j1<m;j1++){
						if(i1==i&&j==j1) continue;
						if(i1==i){
							ans+=(abs(j-j1)+1)*(n*m-m);
							gg+=(n*m-m);
							continue;
						}
						if(j1==j){
							ans+=(abs(i-i1)+1)*(n*m-n);
							gg+=(n*m-n);
							continue;
						}
						int t=__gcd(abs(i-i1),abs(j-j1));
						int ii=abs(i-i1)/t,jj=abs(j-j1)/t;
						ans+=(t+1)*(n*m-min(m/jj+(m%jj==0)?0:1,n/ii+(n%ii==0)?0:1));
						gg+=(n*m-min(m/jj+(m%jj==0)?0:1,n/ii+(n%ii==0)?0:1));
					}
				}
			}
		} 
		cout<<ans-gg/3<<endl;
	}
	
	return 0;
}
