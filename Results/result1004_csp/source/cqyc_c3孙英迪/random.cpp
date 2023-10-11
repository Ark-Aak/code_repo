#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <queue>
#include <bitset>
#include <ctime>
/* #define int long long */
using namespace std;
/* #ifdef ONLINE_JUDGE */

#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 23], *p1 = buf, *p2 = buf, ubuf[1 << 23], *u = ubuf;

/* #endif */
int read() {
	int p = 0, flg = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') flg = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		p = p * 10 + c - '0';
		c = getchar();
	}
	return p * flg;
}
string read_() {
	string ans;
	char c = getchar();
	while (c < '0' || c > '1')
		c = getchar();
	while (c >= '0' && c <= '1') {
		ans += c;
		c = getchar();
	}
	return ans;
}
void write(int x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
const int N = 4005, mod = 998244353;
string mp[N];
int pow_(int x, int k, int p) {
	if (k < 0) return 0;
	int ans = 1;
	while (k) {
		if (k & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p;
		k >>= 1;
	}
	return ans;
}
void Mod(int &x) {
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
}
array <bitset <4005>, 4005> f, g;
signed main() {
	freopen("random.in", "r", stdin);
	freopen("random.out", "w", stdout);
	int n = read(), sum = 0;
	for (int i = 1; i <= n; i++) {
		string tp;
		tp = " " + read_();
		for (int j = 1; j <= n; j++) {
			if (tp[j] == '0') continue;
			sum++;
		}
		mp[i] = tp;
	}
	int m = (n - 1) * n / 2ll - sum;
	/* write(m), puts(""); */
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mp[i][j] == '0') continue;
			f[i][j] = 1;
			g[j][i] = 1;
		}
	}
	int ans = 0;
	int m3 = pow_(2, m - 3, mod),
		m2 = pow_(2, m - 2, mod),
		m1 = pow_(2, m - 1, mod),
		m0 = pow_(2, m, mod);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mp[j][i] == '1' || i == j) continue;
			bitset <4005> tp = (g[i] | f[j] | g[j] | f[i]);
			tp[i] = tp[j] = 1;
			int d0 = n - tp.count();
			int d1 = ((g[i] | f[j]) ^ (g[i] & g[j]) ^ (f[i] & f[j]) ^ (g[i] & f[j])).count();
			int d2 = (g[i] & f[j]).count();
			if (mp[i][j] == '1') {
				ans += 1ll * m2 * d0 % mod, Mod(ans);
				ans += 1ll * m1 * d1 % mod, Mod(ans);
				ans += 1ll * m0 * d2 % mod, Mod(ans);
			}
			else {
				ans += 1ll * m3 * d0 % mod, Mod(ans);
				ans += 1ll * m2 * d1 % mod, Mod(ans);
				ans += 1ll * m1 * d2 % mod, Mod(ans);
			}
		}
	}
	/* write(ans), puts(""); */
	write((1ll * ans * pow_(3, mod - 2, mod)) % mod), puts("");
	/* cout << clock() << endl; */
	return 0;
}
