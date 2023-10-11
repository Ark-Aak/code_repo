#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <tuple>
#include <vector>
#define int long long
using namespace std;
#ifdef ONLINE_JUDGE

#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 23], *p1 = buf, *p2 = buf, ubuf[1 << 23], *u = ubuf;

#endif
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
	while (c < 'A' || c > 'Z')
		c = getchar();
	while (c >= 'A' && c <= 'Z') {
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
const int N = 1e6 + 5, mod = 1e9 + 7;
array <int, N> rx, ry, px, py;
vector <int> isl, cur;
int calc(int x, int y, int m) {
	return (x - 1) * m % mod + y;
}
int pow_(int x, int k, int p) {
	int ans = 1;
	while (k) {
		if (k & 1) ans = ans * x % p;
		x = x * x % p;
		k >>= 1;
	}
	return ans;
}
void Mod(int &x) {
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
}
signed main() {
	freopen("wisdom.in", "r", stdin);
	freopen("wisdom.out", "w", stdout);
	int n = read(), m = read(), q = read();
	for (int i = 1; i <= n; i++)
		rx[i] = (((i - 1) * m + 1 + i * m) * m / 2) % mod;
	for (int i = 1; i <= m; i++)
		/* ry[i] = 1; */
		ry[i] = ((i + i + (n - 1) * m) * n / 2) % mod;
	px.fill(1), py.fill(1);
	for (int i = 1; i <= q; i++) {
		string s = read_();
		int x = read(), y = read();
		if (s[0] == 'R') px[x] = px[x] * y % mod, isl.push_back(x);
		else py[x] = py[x] * y % mod, cur.push_back(x);
	}



	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + rx[i] * px[i] % mod) % mod;
	}
	for (int i = 1; i <= m; i++)
		ans = (ans + ry[i] * py[i] % mod) % mod;
	/* write(py[1]), puts(""); */

	ans -= (1 + n * m) * (n * m) % mod * pow_(2, mod - 2, mod) % mod, Mod(ans);
	int _m = m;
	sort(isl.begin(), isl.end());
	n = unique(isl.begin(), isl.end()) - isl.begin();
	sort(cur.begin(), cur.end());
	m = unique(cur.begin(), cur.end()) - cur.begin();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans -= calc(isl[i], cur[j], _m) * px[isl[i]] % mod, Mod(ans);
			ans -= calc(isl[i], cur[j], _m) * py[cur[j]] % mod, Mod(ans);
			ans += (calc(isl[i], cur[j], _m) * px[isl[i]] % mod * py[cur[j]] % mod + calc(isl[i], cur[j], _m)) % mod, Mod(ans);
		}
	}
	write(ans), puts("");
	return 0;
}
