#include<bits/stdc++.h>
using namespace std;
int l, r, n;
int a[100], ans, p[100];
void dfs(int k) {
	if(k == n + 1) {
		//for(int i = 1; i <= n; i++) cout << a[i];
		//cout << endl; 
		int now = 0;
		for(int i = 1; i <= n; i++) {
		    if(a[i] == 0) continue;
			int num = 0;
			for(int j = i; j <= n; j++) {
				num = num * 10 + a[j];
				if(l <= num && num <= r) {
				    now++;
			    }
			}
			
		}
		if(now > ans) {
			for(int i = 1; i <= n; i++) p[i] = a[i];
			ans = now;
		}
		return;
	}
	for(int i = 0; i <= 9; i++) {
		a[k] = i;
		dfs(k + 1);
	}
}
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> l >> r >> n;
	dfs(1);
	cout << ans << endl;
	for(int i = 1; i <= n; i++) cout << p[i];
	return 0;
} 
/*
104
125
6
*/
