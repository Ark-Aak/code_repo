#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=2005,mod=998244353;
int f[N][N],sum[N];
int vis[2005][100005];
int ans;
signed main(){
	for(int m=1;m<=20;m++){
		for(int n=1;n<=10;n++){
			ans=0;
			memset(f,0,sizeof(f));
			memset(sum,0,sizeof(sum));
			f[0][0]=f[0][1]=1;sum[0]=1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++) f[i][j]=(f[i][j]+sum[i-1])%mod;
				for(int j=1;j<=m;j++){
					for(int k=j*2;k<=m;k+=j){
						f[i][j]=(f[i][j]-f[i-1][k]+mod)%mod;
					}
				}
				for(int j=1;j<=m;j++) sum[i]=(sum[i]+f[i][j])%mod;
			}
			for(int i=1;i<=m;i++){
				ans=(ans+f[n][i])%mod;
			}cout << "vis[" << m << "][" <<n <<"]=" <<ans << "\n";
		}
	}
	return 0;
}


