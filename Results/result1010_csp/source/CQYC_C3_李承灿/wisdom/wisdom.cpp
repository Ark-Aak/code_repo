#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,x,y; 
int ans;
char o;
int a[1000002],b[1000002];
bool visa[1000002],visb[1000002];
int tot,s[1000002],cnt,t[1000002];
const int mod=1000000007;
const int r=500000004;
signed main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	ans=(1+n*m)%mod*(n*m)%mod*r%mod;
	while(k--){
		cin>>o;
		scanf("%lld %lld",&x,&y);
		if(o=='R'){
			if(!visa[x]) a[x]=y,s[++tot]=x,visa[x]=1;
			else a[x]=a[x]*y%mod;
		}
		else{
			if(!visb[x]) b[x]=y,t[++cnt]=x,visb[x]=1;
			else b[x]=b[x]*y%mod;
		}
	}
	for(int i=1;i<=tot;i++){
		ans=(ans+((s[i]-1)*m+s[i]*m+1)%mod*m%mod*r%mod*(a[s[i]]-1)%mod+mod)%mod;
	}
	for(int i=1;i<=cnt;i++){
		ans=(ans+(t[i]+t[i]+(n-1)*m)%mod*n%mod*r%mod*(b[t[i]]-1)%mod+mod)%mod;
		for(int j=1;j<=tot;j++){
			int k=((s[j]-1)*m+t[i])%mod;
			ans=(ans-(k*(a[s[j]]+b[t[i]]-1)%mod)+mod)%mod;
			ans=(ans+k*a[s[j]]%mod*b[t[i]]%mod)%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}


