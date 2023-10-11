/* #define debug */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#define int long long
#define pii pair <int, int>
using namespace std;
#ifndef debug

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
#define fi first
#define se second
const int N = 5e5 + 5;
array <int, N> lp, rp;
array <pii, N> isl;
array <int, N> prl, cur;
int calcl(int x, int y) {
	return lp[y] - lp[x - 1];
}
int calcr(int x, int y) {
	return rp[y] - rp[x - 1];
}
signed main() {
#ifndef debug
	freopen("badge.in", "r", stdin);
	freopen("badge.out", "w", stdout);
#endif
	int n = read(), q = read();
	for (int i = 1; i <= n; i++) {
		int l = read(), r = read();
		lp[l]++, rp[r]++;
		isl[i].fi = l, isl[i].se = r;
	}
	for (int i = 1; i <= n; i++)
		lp[i] += lp[i - 1], rp[i] += rp[i - 1];
	int bs = 450;
	while (q--) {
		int m = read();
		for (int i = 1; i <= m; i++)
			prl[i] = read();
		int ans = 0;
		/* if (m > bs) { */
			for (int i = 1; i <= m; i++)
				cur[prl[i]]++;
			for (int i = 1; i <= n; i++)
				cur[i] += cur[i - 1];
			for (int i = 1; i <= n; i++) {
				if ((cur[isl[i].se] - cur[isl[i].fi - 1]) & 1)
					ans++;
			}
			for (int i = 1; i <= n; i++)
				cur[i] = 0;
		/* } */
		/* else { */
			/* for (int i = 1; i <= m; i++) { */
				/* for (int j = i; j <= m; j += 2) { */
					/* int l1 = prl[i - 1] + 1, r1 = prl[i] - 1; */
					/* int l2 = prl[j] + 1, r2 = prl[j + 1] - 1; */

				/* } */
			/* } */
		/* } */

		write(ans), puts("");
	}
	return 0;
}
