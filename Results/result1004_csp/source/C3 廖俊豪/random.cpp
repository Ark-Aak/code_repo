#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
int n,m,res,tmp,ans;
int to[4005][4005];
int f[10000005];
int poww(int x,int y){
	int sum=1;
	while(y){
		if(y&1)sum=sum*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return sum;
}
signed main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%lld",&n);
	if(n<3){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%1lld",&to[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(to[i][j]+to[j][i]==0)m++;
			else res++;
//			if(i%100==0&&j%100==0)printf("%lld %lld\n",m,res);
		}
	}
	if(res==0){
		printf("%lld\n",(n*(n-1)*(n-2)/3%mod*poww(2,m-3))%mod);
		return 0;
	}
	f[0]=1;
	for(int i=1;i<=m;i++){
		f[i]=f[i-1]+f[i-1];
		if(f[i]>=mod)f[i]-=mod;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(to[j][i])continue;
			for(int k=1;k<=n;k++){
				if(k==i)continue;
				if(k==j)continue;
				if(to[k][j])continue;
				if(to[i][k])continue;
				ans+=f[m-3+to[i][j]+to[j][k]+to[k][i]];
				if(ans>=mod)ans-=mod;
			}
		}
	}
	cout<<(ans*poww(3,mod-2))%mod;
	return 0;
}
