#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n,Q;

const int N=2e5+5;

int a[N];


signed main(){
	freopen("easiest.in","r",stdin);
	freopen("easiest.out","w",stdout);
	scanf("%lld%lld",&n,&Q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1,ans=0,opt,l,r,l1,r1;i<=Q;i++){
		scanf("%lld%lld%lld%lld%lld",&opt,&l,&r,&l1,&r1);
		ans=0;
		if(opt==1){
			ans+=(l1-l);
				
				if(a[r1+1]<a[l1-1]&&r1+1<=r) ans++;
				for(int j=r1+2;j<=r;j++){
					if(a[j]>=a[j-1]) continue; 
					else ans++;
				}
				cout<<ans<<endl;
			}
		}
	return 0;
}
