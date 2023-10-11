#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int a,b,q=1;q<=n;q++){
		cin>>a>>b;
		int ans=0;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				int aa=i,bb=j,g=__gcd(aa,bb);
				aa/=g;
				bb/=g;
				ans+=aa+bb-2;
				ans%=1000000007;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

