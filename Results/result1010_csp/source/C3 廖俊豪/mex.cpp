#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n;
int b[20];
int f[18][1<<18];
inline int w(int x){
	for(int i=0;i<n;i++)
		if(((x>>i)&1)==0)return i;
	return n;
}
signed main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>b[i];
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int s=0;s<(1<<n);s++){
			for(int j=0;j<=min(n-1,b[i]);j++){
				f[i][s|(1<<j)]+=f[i-1][s];
				if(f[i][s|(1<<j)]>=mod)f[i][s|(1<<j)]-=mod;
			}
			if(b[i]>=n)f[i][s]+=(1ll*f[i-1][s]*(b[i]-n+1))%mod;
			if(f[i][s]>=mod)f[i][s]-=mod;
//			cout<<i<<","<<s<<":"<<f[i][s]<<endl;
		}
	}
	int ans=0;
	for(int i=0;i<(1<<n);i++){
//		cout<<f[n][i]<<endl;
		ans=(ans+1ll*f[n][i]*w(i))%mod;
	}
	cout<<ans<<endl;
	return 0;
} 
