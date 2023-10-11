#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5010;
int b[N], ans = 0, d[N];
map<int, int>tmp;
const int Mod = 1e9 + 7;
int n, Max;
void dfs(int x) {
	if(x == n + 1) {
		for(int i = 0; i <= Max; i++) tmp[i] = 0;
		for(int i = 1; i <= n; i++) tmp[d[i]] = 1;
		for(int i = 0; i <= Max; i++) {
			if(!tmp[i]) {
				ans = (ans + i) % Mod;
				return;
			}
		}
		return;
	}
	for(int i = 0; i <= b[x]; i++) {
		d[x] = i;
		dfs(x + 1);
		d[x] = 0;
	}
}
signed main() {
	
	freopen("mex.in", "r", stdin);
	freopen("mex.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &b[i]), Max = max(Max, b[i]);
	dfs(1);
	cout << ans % Mod;
}
