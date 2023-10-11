#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=998244353;
int n;
char a[5005][5005];
int same[4005][4005];
int dif1[4005][4005]; 
int dif2[4005][4005]; 
bool flag;
int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=(x*res)%Mod;
		x=(x*x)%Mod;
		y>>=1;
	}
	return res;
}
int ggg[4];
signed main() {
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
	} 
	int kk=n*(n-1)/2;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i][j]=='1'||a[j][i]=='1') kk--,flag=1;
		}
	}
	if(n<=500){
		int ans=0;
		ggg[0]=1; 
		ggg[1]=ksm(2,kk-1)%Mod;
		ggg[2]=ksm(2,kk-2)%Mod;
		ggg[3]=ksm(2,kk-3)%Mod;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[j][i]=='1'||i==j) continue;
				for(int t=1;t<=n;t++){
					if(a[i][t]=='1'||a[t][j]=='1'||i==t||j==t) continue;
					int gg=3;
					if(a[i][j]=='1') gg--;
					if(a[j][t]=='1') gg--;
					if(a[t][i]=='1') gg--;
					ans+=ksm(2,kk-gg)%Mod;
					if(ans>Mod)ans-=Mod;
				}
			}
		}
		cout<<ans%Mod*ksm(3,Mod-2)%Mod;
		return 0;
	}
	if(!flag){
		int ans=0;
		ggg[1]=ksm(2,kk-1)%Mod;
		ggg[2]=ksm(2,kk-2)%Mod;
		ggg[3]=ksm(2,kk-3)%Mod;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				int gg=3;
				ans+=ggg[gg]*(n-2)%Mod;
				ans%=Mod;
			}
		}
		cout<<ans*ksm(3,Mod-2)%Mod;
		return 0;
	}
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
