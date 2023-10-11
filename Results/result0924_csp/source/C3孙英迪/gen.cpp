#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <vector>
#include <cmath>
#include <ctime>
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
const int N = 2e5 + 5, M = 2e6 + 5, mod = 1e9 + 7;
array <int, N> deg;

vector <int> isl;
array <int, N> cur;
void Mod(int &x) {
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
}
int main() {
	freopen("gen.in", "r", stdin);
	freopen("gen.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		deg[x]++, deg[y]++;
	}
	int sq = 1250;
	int ans = 0;
	for (int i = 1; i <= n; i++) {

		for (int j = 0; j <= sq; j++)
			ans += (deg[i] | j) * (deg[i] ^ j) * (deg[i] & j) * cur[j] % mod, Mod(ans);

		for (auto x : isl)
			ans += (deg[i] | x) * (deg[i] ^ x) * (deg[i] & x), Mod(ans);

		if (deg[i] <= sq) cur[deg[i]]++;
		else isl.push_back(deg[i]);


	}
	write(ans), puts("");
	/* cout << clock() << endl; */
	return 0;
}
