#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
int n;
string s[505];
int dp[505],Dp[505];
int a[505][505];
int f=0,F=1;
int g=0,G=1;
signed main(){
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]=' '+s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		memset(dp,0,sizeof dp);
		memset(Dp,0,sizeof Dp);
		Dp[0]=1;
		int maxn=0;
		for(int j=1;j<=n;j++){
			if(s[i][j]=='R'){
				for(int k=maxn;k>=0;k--){
					dp[k+1]+=dp[k]+a[i][j]*Dp[k];
					Dp[k+1]+=Dp[k];
					dp[k+1]%=mod;
					Dp[k+1]%=mod;
				}
				maxn++;
			}
			if(s[i][j]=='L'){
				for(int k=1;k<=maxn;k++){
					dp[k-1]+=dp[k]+a[i][j]*Dp[k];
					Dp[k-1]+=Dp[k];
					dp[k-1]%=mod;
					Dp[k-1]%=mod;
				}
			}
		}
		f=(f*Dp[0]+dp[0]*F)%mod;
		F=(F*Dp[0])%mod;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			swap(s[i][j],s[j][i]);
			swap(a[i][j],a[j][i]);
		}
	}
	for(int i=1;i<=n;i++){
		memset(dp,0,sizeof dp);
		memset(Dp,0,sizeof Dp);
		Dp[0]=1;
		int maxn=0;
		for(int j=1;j<=n;j++){
			if(s[i][j]=='D'){
				for(int k=maxn;k>=0;k--){
					dp[k+1]+=dp[k]+a[i][j]*Dp[k];
					Dp[k+1]+=Dp[k];
					dp[k+1]%=mod;
					Dp[k+1]%=mod;
				}
				maxn++;
			}
			if(s[i][j]=='U'){
				for(int k=1;k<=maxn;k++){
					dp[k-1]+=dp[k]+a[i][j]*Dp[k];
					Dp[k-1]+=Dp[k];
					dp[k-1]%=mod;
					Dp[k-1]%=mod;
				}
			}
		}
		g=(g*Dp[0]+dp[0]*G)%mod;
		G=(G*Dp[0])%mod;
	}
	cout<<(f*G+g*F)%mod;
	return 0;
}
