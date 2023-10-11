#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
const int mod = 1e9 + 7;
const int inv = 500000004;
int n, m, k, A[1000005], B[1000005], cnta, cntb, ans, sum, sumA;
signed main() {
	freopen("wisdom.in", "r", stdin);
	freopen("wisdom.out", "w", stdout);
	n = read(); m = read(); k = read();
	for(int i = 1; i <= max(n, m); ++i) {
		A[i] = 1, B[i] = 1;
	}
	while(k--) {
		char op;
		cin>>op;
		if(op == 'R') {
			int x, y;
			x = read(); y = read();
			A[x] *= y;
			A[x] %= mod;
		}
		else {
			int x, y;
			x = read(); y = read();
			B[x] *= y;
			B[x] %= mod;
		}
	}
	for(int i = 1; i <= n; ++i) {
		ans += (((i - 1) * m % mod + 1 + i * m) % mod * m % mod * inv) % mod * A[i];
		ans %= mod;
		sumA += A[i];
		sumA %= mod; 
		sum += ((i - 1) * m + 1) % mod * A[i] % mod;
	}
	for(int i = 1; i <= m; ++i) {
		ans += (sum + (i - 1) * sumA) % mod * (B[i] - 1);
		ans %= mod;
	}
	cout<<ans;
	return 0;
}
