#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e3+5,M=1e5+5,mod=998244353;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,dp[N][N],sum[N],s[N][155],tp[N],maxn;
void add(int &a,int b){if((a+=b)>=mod) a-=mod;}
void deal(int x){
	if(x==1) return;
	int id=x;
	for(int i=1;i*i<=x;i++){
		if(x%i==0){
			s[id][++tp[id]]=i;
			if(i!=1&&i*i!=x) s[id][++tp[id]]=x/i;
		} 	
	}
	return;
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) dp[n][i]=1,sum[n]++;
	for(int i=1;i<=m;i++){
		deal(i);
//		maxn=max(maxn,tp[i]);
	} 
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=m;j++){//a[i]

			dp[i][j]=sum[i+1];//a[i]<=a[i+1]
			
			for(int k=1;k<=tp[j];k++)//d|a[i]
				dp[i][j]=(dp[i][j]-dp[i+1][s[j][k]]+mod)%mod;
		
			add(sum[i],dp[i][j]);//sum
		}
	}
	printf("%lld",sum[1]);
	return 0;
}
/*
5 3
63
*/
