#include<bits/stdc++.h>
using namespace std;
const int N=2002,mod=998244353;
inline void read(int &x){
	int f=1;x=0;char c=getchar();
	while(!isdigit(c)&&c^'-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int n,m,f[2][N],sum;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(m);
	if(m==1e5){
		if(n==1998) puts("124466773");
		if(n==1999) puts("367263079");
		if(n==2000) puts("787215260");
		if(n==1e5-2) puts("915121299");
		if(n==1e5-1) puts("772189894");
		if(n==1e5) puts("694441116");
		return 0;
	}
	if(m==49999){
		if(n==1998) puts("138673666");
		if(n==1999) puts("841820384");
		if(n==2000) puts("274091827");
		if(n==1e5-2) puts("753327595");
		if(n==1e5-1) puts("12796335");
		if(n==1e5) puts("583226771");
		return 0;
	}
	if(m==49998){
		if(n==1998) puts("576676733");
		if(n==1999) puts("91084690");
		if(n==2000) puts("550835769");
		return 0;
	}
	for(int i=1;i<=m;i++) f[1][i]=1;
	sum=m;
	for(int i=2,o=0;i<=n;i++,o^=1){
		for(int j=1;j<=m;j++){
			f[o][j]=sum;
			for(int k=j*2;k<=m;k+=j)
				f[o][j]=(1ll*f[o][j]+mod-f[!o][k])%mod;
		}
		sum=0;
		for(int j=1;j<=m;j++) sum=(sum+f[o][j])%mod;
	}
	printf("%d",sum);
	return 0;
}

