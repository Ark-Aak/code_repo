#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, Mod;
const int N = 1e5 + 10;
int ans = 1;
signed main() {
	freopen("ring.in", "r", stdin);
	freopen("ring.out", "w", stdout);
	cin >> n >> Mod;
	for(int i = 1; i <= n; i++) ans = (ans * i) % Mod;
	cout << ans;
}
