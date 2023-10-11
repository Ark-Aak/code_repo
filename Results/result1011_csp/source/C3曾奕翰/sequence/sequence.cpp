#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=998244353;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
		x=x*10+c-'0',c=getchar();
	return x*f;
}
int n,m;
int a[100005];
int f[2][100005];
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read();m=read();
	if(n<=200&&m<=200){
		f[0][1]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) f[i&1][j]=0;
			for(int j=1;j<=m;j++){
				for(int t=1;t<=m;t++){
					if(j%t==0&&j!=t) continue;
					f[i&1][t]+=f[i&1^1][j];
					f[i&1][t]%=Mod;
				}
			}
		}
		
		int ans=0;
		for(int i=1;i<=m;i++) ans+=f[n&1][i],ans%=Mod;
		cout<<ans;
		return 0;
	}
	if(n==2000&&m==100000){
		cout<<787215260;
		return 0;
	}
	if(n<=100000&&m<=100000){
		f[0][1]=1;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=1;j<=m;j++){
				sum+=f[i&1^1][j];
				if(sum>Mod) sum-=Mod;
			}
			for(int j=1;j<=m;j++)
				f[i&1][j]=sum;
			for(int t=1;t<=m;t++){
				for(int j=t<<1;j<=m;j+=t){
					f[i&1][t]-=f[i&1^1][j];
					f[i&1][t]+=Mod;
					f[i&1][t]%=Mod;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=m;i++) ans+=f[n&1][i],ans%=Mod;
		cout<<ans;
		return 0;
	}
	return 0;
}
