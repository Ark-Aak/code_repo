#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int x[1003],ans,s=1;
signed main(){
	freopen("crazy.in","r",stdin);
	freopen("crazy.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	sort(x+1,x+n+1);
	for(int i=2;i<=n;i++){
		if(x[i]==x[i-1]+1) s++;
		else{
			if(s%2==0) ans+=2;
			else{
				int z=1;
				for(int j=2;j*j<=s;j++){
					if(s%j==0){
						z=3;
						break;
					}
				}
				ans+=z;
			}
			s=1;
		}
	}
	if(s%2==0) ans+=2;
	else{
		int z=1;
		for(int j=2;j*j<=s;j++){
			if(s%j==0){
				z=3;
				break;
			}
		}
		ans+=z;
	}
	printf("%lld",ans);
	return 0;
}


