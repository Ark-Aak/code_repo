//55
#include<bits/stdc++.h>
#define int long long
#define MX 500005
using namespace std;
int n,m,l,a[MX],f[MX];
signed main(){
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){scanf("%lld",&a[i]);a[i]--;}
	memset(f,0x3f,sizeof(f));
	sort(a+1,a+1+n);f[0]=0;
	for(int i=1;i<=n;i++){
		//while()
		l=max(l,i-m);
		for(int j=l/*max(0ll,i-m)*/;j<i;j++){
			f[i]=min(f[i],f[j]+a[i]*(n-j));
			if(f[i]==f[j]+a[i]*(n-j)) l=j;
			//cout<<setw(5)<<f[j]+a[i]*(n-j);
		}//cout<<l<<' ';
		//cout<<'\n';
	}cout<<f[n]*2ll;
	return 0;
} 
