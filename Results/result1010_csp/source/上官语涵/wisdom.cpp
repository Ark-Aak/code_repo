#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
int R[N], C[N]; 
const int Mod = 1e9 + 7;
int n, m, k;
signed main() {
	freopen("wisdom.in", "r", stdin);
	freopen("wisdom.out", "w", stdout);
	
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1; i <= n; i++) R[i] = 1;
	for(int i = 1; i <= m; i++) C[i] = 1;
	while(k--) {
		char op;
		int x, y;
		scanf("%s%lld%lld", &op, &x, &y);
		if(op == 'R') R[x] = (R[x] * y) % Mod;
		else C[x] = (C[x] * y) % Mod;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			ans = (ans + (((i - 1) * m + j) % Mod * R[i] % Mod * C[j] % Mod)) % Mod;
		}
	}
	printf("%lld", ans);
}
//50
