#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[10005];
int b[10005];
long long f[405][405][405];
//char s[1000005];
//int l0,r0,l1,r1;
signed main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	int T=1;
	//scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			b[i]=a[i];
			
		}
		sort(b+1,b+n+1);
		reverse(b+1,b+n+1);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k+1;j++)
				for(int qwq=0;qwq<=n+1;qwq++)
					f[i][qwq][j]=1e16;
		f[0][0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(k+1,i);j++){
				if(i==1){
					for(int qwq=1;qwq<=n;qwq++){
						int t=qwq;
						if(a[t]>=a[i]&&j<=min(k+1,i)) f[i][t][j+1]=min(f[i][t][j+1],f[0][0][0]+(b[t]-a[1]));
						else break;
						
					}
				}
				else{
					int pof=1e16;
					for(int gg=1;gg<=n;gg++){
						if(j<=min(k+1,i)) pof=min(pof,f[i-1][gg][j]);
					}
					for(int qwq=1;qwq<=n;qwq++){
						int t=qwq;
						if(b[t]<a[i]) break;
						f[i][t][j+1]=min(f[i][t][j+1],pof+(b[t]-a[i]));
						
						if(a[i]<=b[t]){
							f[i][t][j]=min(f[i][t][j],f[i-1][t][j]+(b[t]-a[i]));
						}
						
					}
				}
			}
		}
		int ans=1e16;
		for(int i=1;i<=n;i++){
			for(int t=0;t<=k+1;t++){
				ans=min(ans,f[n][i][t]);
			}
		}
		cout<<ans;
	}
	return 0;
}
