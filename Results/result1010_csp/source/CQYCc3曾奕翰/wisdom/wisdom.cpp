#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=1e9+7;
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
int n,m,k;
int r[1000005];
int s[1000005];
int ans[1000005];
int cr[100005],cs[100005],totr,tots;
bool viss[1000005];
bool visr[1000005];
signed main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	n=read(),m=read();k=read();
	for(int i=1;i<=n;i++) r[i]=1;
	for(int j=1;j<=m;j++) s[j]=1;
	for(int i=1;i<=k;i++){
		char ch;int x,y;
		scanf("%c",&ch);x=read(),y=read();
		if(ch=='R') r[x]*=y,r[x]%=Mod;
		else s[x]*=y,s[x]%=Mod;
	}
	for(int i=1;i<=n;i++)
		if(r[i]!=1) cr[++totr]=i,visr[i]=1;
	for(int i=1;i<=m;i++)
		if(s[i]!=1) cs[++tots]=i,viss[i]=1;
	int sans=0,num=0,sum=0,xum=0,k=0;
	for(int i=1;i<=m;i++){
		if(!viss[i]) sans+=i,sans%=Mod,num++;
		else sum+=i*s[i]%Mod,k+=s[i],sum%=Mod;
	}
	for(int i=1;i<=n;i++){
		ans[i]+=(sans+num*(i-1)%Mod*m%Mod)*r[i]%Mod;
		if(ans[i]>Mod) ans[i]-=Mod;
		if(!visr[i]) ans[i]+=(sum+(i-1)*m%Mod*k)%Mod;
		if(ans[i]>Mod) ans[i]-=Mod;
	}
	for(int i=1;i<=totr;i++){
		for(int j=1;j<=tots;j++){
			int S=cs[j],R=cr[i];
			ans[R]+=s[S]*r[R]%Mod*((R-1)*m+S)%Mod;
			if(ans[R]>Mod) ans[R]-=Mod;
		}
	}
	int answer=0;
	for(int i=1;i<=n;i++) answer+=ans[i],answer%=Mod;
	printf("%lld",answer%Mod);
	return 0;
}
