#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define inv 500000004
#define N 200005
using namespace std;
int f(int x, int y) {
    return (x ^ y) * (x | y) % mod * (x & y) % mod;
}
int n, m, ans;
int d[N], h[N];
signed main() {
    freopen("gen.in", "r", stdin);
    freopen("gen.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
	}
	if(n <= 2000) {
	    for(int i = 1; i <= n; i++)
	    for(int j = i + 1; j <= n; j++)
	        ans = (ans + f(d[i], d[j])) % mod;
	    cout << ans;
	} 
	else {
	    for(int i = 1; i <= n; i++) h[d[i]]++;
		for(int i = 0; i <= 2000; i++)
	    for(int j = 0; j <= 2000; j++)
	        ans = (ans + f(i, j) * h[i] % mod * h[j] % mod) % mod;
	    cout << ans * inv % mod;
	}
    return 0;
}
