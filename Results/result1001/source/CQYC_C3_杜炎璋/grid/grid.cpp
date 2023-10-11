#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		if(min(n,m)<2) printf("0");
		else {
			if(n>m) swap(n,m);
			int ans=(m-1)*12;
			for(int i=1;i<=m;i++) {
				int l=i-1,r=m-i;
				ans+=(l)*(r-1)*(r);
				ans+=(r)*(l-1)*(l);
				ans+=2*((l)*(r)*4);
				ans+=(l)*(r)*2*3;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

/*
3
2 2
2 3
3 2
*/

