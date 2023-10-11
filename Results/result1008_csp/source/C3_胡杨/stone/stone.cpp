#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
const int mod = 1e9 + 7;
int n, k, ans;
int a[110];
int ksm(int x,int y){
	int s = 1;
	while(y){
		if(y & 1) s = s * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
}
void dfs(int x){
	if(x > n){
		int s = 0;
		for(int i = n ; i >= 1 ; i--){
			if(a[i] + s >= i && a[i] <= i && i != 1){
				ans = (ans + (a[i] + s) % i) % mod;
				s = (s + (a[i] + s) / i) % mod;
			}
			else ans = (ans + (a[i] + s) % i) % mod;
		}
		return ;
	}
	for(int i = 0 ; i <= k ; i++){
		a[x] = i;
		dfs(x + 1);
	}
} 
signed main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
    read(n); read(k);
    dfs(1);
    printf("%lld\n", ans);
	return 0;
}


