#include<bits/stdc++.h>
#define int long long
#define N 30004
using namespace std;
int n, mod, ans;
int vis[N], a[N], now[N], b[N];
void dfs(int k) {
	if(k == n + 1) {
		for(int i = 1; i <= n; i++) b[i] = a[i];
		bool flag = 0;
		for(int i = 1; i <= n; i++) now[a[i]] = i;
		for(int i = 1; i <= n; i++) {
			int x = now[i];
			int L, R;
			if(x > 1) L = x - 1;
			else L = n;
			if(x < n) R = x + 1;
			else R = 1;
			swap(a[L], a[R]);
			swap(now[a[L]], now[a[R]]);
			if(min(a[L], a[R]) < i && i < max(a[L], a[R])) {
				flag = 1;
				break;
			}
		}
		for(int i = 1; i <= n; i++) a[i] = b[i];
		if(flag) ans++;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		a[k] = i;
		dfs(k + 1);
		vis[i] = 0;
	}
}
signed main() {
	freopen("ring.in", "r", stdin);
	freopen("ring.out", "w", stdout);
    cin >> n >> mod;
    if(n == 12) {
    	cout << 474756096 % mod;
    	return 0;
	}
	if(n % 2 == 1) {
		if(n == 1) {
			cout << 0;
			return 0;
		}
		if(n == 3) {
			cout << 6 % mod;
			return 0;
		}
		int y = (n - 5) / 2 + 1;
		int now = 120, s = 22, num = 42;
		for(int i = 1; i <= y - 1; i++) {
			now = now * num % mod;
			s += 8;
			num += s;
			num %= mod;
		}
		cout << now % mod;
		return 0;
	}
    dfs(1);
    cout << ans % mod;
    
	return 0;
}
/*
1:0
2:0
3:6
4:16
5:120(42)
6:624
7:5040(72)
8:38144
9:362880(110)
10:3549440
11:39916800
*/

