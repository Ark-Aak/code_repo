#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a;
int e[100005],w[100005];
string s;
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld %lld",&n,&k);
		cin>>s;
		for(int i=0;i<n;i++) e[i]=w[i]=0;
		int o=0,p=0;
		for(int i=0;i<n;i++){
			if(s[i]-'0'>0) o++;
			else p++;
			e[i]=o;
			w[i]=p;
		}
		int z=0;
		for(int i=0;i+k<=n;i++){
			if(e[i+k-1]-e[i-1]==o||w[i+k-1]-w[i-1]==p){
				z=1;
				printf("win\n");
				break;
			}
		}
		if(z==0) printf("tie\n");
	}
	return 0;
}


