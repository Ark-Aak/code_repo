#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn=510;
const int mod=998244353;
int f[maxn][maxn],g[maxn][maxn];
char ch[maxn][maxn];
int a[maxn][maxn];
const int maxm=1010;
int pre[maxm],suf[maxm];
int tb[maxm],tc[maxm],tot=0;

signed main(){
	freopen("cat.in", "r", stdin);
	freopen("cat.out", "w", stdout);
	int n;
	
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	
	// for(int i=1;i<=n;i++) printf("%s\n",ch[i]+1);
	
	for(int i=1;i<=n;i++){
		f[0][0]=1;
		g[0][0]=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k<=n;k++){
				f[j][k]=f[j-1][k];
				g[j][k]=g[j-1][k];
				if(ch[i][j]=='L'&&k!=n){
					f[j][k]=(f[j][k]+f[j-1][k+1]*(k+1)%mod)%mod;
					g[j][k]=(g[j][k]+g[j-1][k+1]*(k+1)%mod+f[j-1][k+1]*(k+1)%mod*a[i][j]%mod)%mod;
				}else if(ch[i][j]=='R'&&k!=0){
					f[j][k]=(f[j][k]+f[j-1][k-1])%mod;
					g[j][k]=(g[j][k]+g[j-1][k-1]+f[j-1][k-1]*a[i][j]%mod)%mod;
				}
			}
		}
		// printf("\n%d\n",i);
		// for(int j=1;j<=n;j++) printf("%d %d\n",f[j][0],g[j][0]);
		tb[++tot]=f[n][0];
		tc[tot]=g[n][0];
	}
	for(int i=1;i<=n;i++){
		f[0][0]=1;
		g[0][0]=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k<=n;k++){
				f[j][k]=f[j-1][k];
				g[j][k]=g[j-1][k];
				if(ch[j][i]=='U'&&k!=n){
					f[j][k]=(f[j][k]+f[j-1][k+1]*(k+1)%mod)%mod;
					g[j][k]=(g[j][k]+g[j-1][k+1]*(k+1)%mod+f[j-1][k+1]*(k+1)%mod*a[j][i]%mod)%mod;
				}else if(ch[j][i]=='D'&&k!=0){
					f[j][k]=(f[j][k]+f[j-1][k-1])%mod;
					g[j][k]=(g[j][k]+g[j-1][k-1]+f[j-1][k-1]*a[j][i]%mod)%mod;
				}
			}
		}
		tb[++tot]=f[n][0];
		tc[tot]=g[n][0];
	}
	
	// for(int i=1;i<=tot;i++) printf("%lld %lld\n",tb[i],tc[i]);
	
	pre[0]=suf[tot+1]=1;
	for(int i=1;i<=tot;i++) pre[i]=pre[i-1]*tb[i]%mod;
	for(int i=tot;i>=1;i--) suf[i]=suf[i+1]*tb[i]%mod;
	
	int res=0;
	
	for(int i=1;i<=tot;i++) res=(res+pre[i-1]*suf[i+1]%mod*tc[i]%mod)%mod;
	
	printf("%lld\n",res);
	
	return 0;
}
