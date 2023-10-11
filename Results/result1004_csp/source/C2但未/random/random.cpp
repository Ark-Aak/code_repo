#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<1)+(x<<3)+s-48;s=getchar();}
	return x*f;
}
const int Maxn=4005,Mod=998244353;
inline int ksm(int x,int k){
	int res=1;
	for(;k;k>>=1){
		if(k&1)res=1ll*res*x%Mod;
		x=1ll*x*x%Mod;
	}
	return res;
}
int n,cnt;
int e[Maxn][Maxn];
inline void solve40(){// bu4 zhi1 dao4 you3 mei2 you3 si4 shi2 // wo3 zhi1 dao4 li
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((e[i][j]||(!e[j][i]))&&i!=j)
				for(int k=1;k<=n;k++)
					if((i!=k&&k!=j)&&(e[j][k]||(!e[k][j]))&&(e[k][i]||(!e[i][k]))){
						int cnt1=3-e[i][j]-e[j][k]-e[k][i];
						ans=(ans+ksm(2,cnt-cnt1))%Mod;//,printf("%d %d %d %d\n",i,j,k,cnt-cnt1);
					}
	printf("%lld",ans*ksm(3,Mod-2)%Mod);
}
char ch[Maxn];
int main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for(int j=1;j<=n;j++)
			e[i][j]=ch[j]-'0',cnt+=e[i][j];
	}
	if(!cnt)printf("%lld\n",1ll*(1ll*n*n*n-1ll*(3ll*n-2ll)*n)%Mod*ksm(2,n*(n-1)/2-3)%Mod*ksm(3,Mod-2)%Mod);
	else{
		cnt=n*(n-1)/2-cnt;
		solve40();
	}
	return 0;
}

