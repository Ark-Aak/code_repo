#include<bits/stdc++.h>
#define int long long
using namespace std;
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
const int Mod=1e9+7;
int n;
int a[50005];
int f[5005][5005];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=(res*a)%Mod;
		a=(a*a)%Mod;
		b>>=1;
	}
	return res;
}
signed main(){
//	freopen("mex.in","r",stdin);
//	freopen("mex.out","w",stdout);	
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int sans=0;
	for(int i=1;i<=n;i++) sans+=a[i];
	int s=1,ans=0;
	for(int i=1;i<=n;i++){
		f[i][1]=sans-a[i];
		s*=i,s%=Mod;
	}
	ans+=s*n;
	s=s*ksm(n,Mod-2)%Mod;
	ans+=sans*s;
	s=s*ksm(n-1,Mod-2)%Mod;
	ans%=Mod; 
	for(int i=2;i<n-1;i++){
		int num=0;
		for(int j=1;j<=n;j++){
			num+=f[j][i-1]*a[j]%Mod;
		}
		num=num*ksm(i,Mod-2)%Mod;
		ans+=(num*s)%Mod;
		ans%=Mod;
		for(int j=1;j<=n;j++){
			f[j][i]=(Mod+num-f[j][i-1]*a[j])%Mod;
		}
		s=s*ksm(n-i,Mod-2)%Mod;
	}
	cout<<ans%Mod;
	return 0;
}

