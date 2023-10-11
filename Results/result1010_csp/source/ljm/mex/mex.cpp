#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int n ,ans;
int a[1000], b[1000], p[1000];
void dfs(int k) {
	if(k == n + 1) {
		for(int i = 0; i <= 11; i++) p[i] = 0;
		for(int i = 1; i <= n; i++) p[a[i]]++;
		int num = 0;
		for(int i = 0; i <= 11; i++) {
			if(p[i] == 0) {
				num = i;
				break;
			}
		}
		ans += num;
		ans %= mod;
		return;
	}
	for(int i = 0; i <= b[k]; i++) {
		a[k] = i;
		dfs(k + 1);
	}
}
signed main() {
	freopen("mex.in", "r", stdin);
	freopen("mex.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> b[i];
    dfs(0);
    cout << ans;
	return 0;
}

