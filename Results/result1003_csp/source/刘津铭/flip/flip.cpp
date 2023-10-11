#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;

signed main() {
	freopen("flip.in", "r", stdin);
	freopen("flip.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int ans = 1;
	while(k--) ans *= n;
	cout << ans;
	return 0;
} 
