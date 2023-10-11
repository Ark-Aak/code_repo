#include<bits/stdc++.h>
#define int long long
using namespace std;
int Q;
int x, n;
signed main(){
    freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
    cin >> Q;
    while(Q--){
    	scanf("%lld %lld", &x, &n);
    	int a = x % 10;
    	int b = (x / 10) % 10;
    	int c = (x / 100) % 10;
    	int ans = 0;
    	if(n == 0) ans = 1;
    	else if(a != b && b != c && a != c){
    		if(n == 1) ans = 24;
    		else ans = 27;
		} 
    	else if((a == b && b != c) || (a == c && b != c) || (b == c && a != b)){
    		if(n == 1) ans = 7;
    		else ans = 8;
		}
		else ans = 1;
		printf("%lld\n",ans);
	}
	return 0;
}

