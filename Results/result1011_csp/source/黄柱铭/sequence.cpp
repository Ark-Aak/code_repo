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
int f[2][100005],sum[N];
int n,m,ans;
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();
	m=read();
	//--------50ptsO(nm log m)------------
	f[0][1]=f[0][0]=1;
	sum[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) f[i&1][j]=0;
		for(int j=1;j<=m;j++) f[i&1][j]=(f[i&1][j]+sum[i-1])%mod;
		for(int j=1;j<=m;j++){
			for(int k=j*2;k<=m;k+=j){
				f[i&1][j]=(f[i&1][j]-f[(i-1)&1][k]+mod)%mod;
			}
		}
		for(int j=1;j<=m;j++){
			sum[i]=(sum[i]+f[i&1][j])%mod;
		}
	}
	for(int i=1;i<=m;i++){
		ans=(ans+f[n&1][i])%mod;
	}cout << ans;
	return 0;
}


