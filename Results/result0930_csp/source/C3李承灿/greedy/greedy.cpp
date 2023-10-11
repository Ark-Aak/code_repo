#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
int m;
int mod=147744151;
void f(int x,int s){
	if(s==1||x==1||x==2){
		ans=(ans+x)%mod;
		return;
	}
	int o=1;
	while((o<<1)<=x) o<<=1,ans++;
	f(o/2-1,s-1);
}
signed main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	if(k==1||n==1||n==2){
		printf("%lld",(n-1)%mod);
		return 0;
	}
	for(int i=1;i<=k;i++){
		n=(double)(sqrt(n)+0.99999);
		ans=(ans+n)%mod;
	}
	printf("%lld",ans);
	return 0;
}


