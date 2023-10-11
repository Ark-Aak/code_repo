#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long s=0,w=1;char c=getchar();
	while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}
	while(c>=48&&c<=57) s=(s<<1)+(s<<3)+c-48,c=getchar();
	return s*w;
}
const long long mod=10000007;
long long q1[1000006],q2[1000006];
int main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	long long n,m,k;
	n=read(),m=read(),k=read();
	if(n*m<=100000000){
		long long cnt1=0,cnt2=0; 
		for(long long i=1;i<=n;i++)q1[i]=1;
		for(long long i=1;i<=m;i++)q2[i]=1;
		for(long long i=1;i<=k;i++){
			char rs,x,y;
			cin>>rs;
			x=read(),y=read();
			rs=='R'?q1[x]=q1[x]*y%mod:q2[x]=q2[x]*y%mod;
		}
		long long ans=0;
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=m;j++)
				ans+=q1[i]*q2[j]%mod*((i-1)*m+j)%mod;
		cout<<ans;
	}
	else{
		cout<<(1+n*m)%mod*n%mod*m%mod/2;
	}
	return 0;
}
