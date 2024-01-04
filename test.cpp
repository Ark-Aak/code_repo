#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int Pow(int a, int n) {
	if(n == 0) return 1;
	if(n == 1) return a % mod;
	int x = Pow(a, n / 2);
	if(n % 2 == 0) return x * x % mod;
	else return x * x % mod * a % mod;
}
int inv(int x) {
	while (x < 0) x = (x + mod) % mod;
	return Pow(x, mod - 2);
}
int n, m, q, ans;
signed main() {
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) {
		int p = i * (n - i + 1) % mod * inv((n + 1) * n / 2 % mod) % mod;
		int P = (1 - p * inv(2) % mod + mod) % mod;
		int z = (2 * m % mod * P % mod + 1) % mod * inv(2 * m + 1) % mod;
		int S = (Pow(z, q) - 1 + mod) % mod * inv(z - 1) % mod;	
		ans = (ans + p * inv(2 * m + 1) % mod * (m - 1) % mod * inv(2) % mod * ((q - S + mod) % mod) % mod) % mod;
	}
	cout << ans * Pow((2 * m + 1) % mod * n % mod * (n + 1) % mod * inv(2) % mod, q) % mod;
	return 0;
}