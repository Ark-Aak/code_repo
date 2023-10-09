#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
using namespace std;
/* #ifdef ONLINE_JUDGE */

/* #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++) */
/* char buf[1 << 23], *p1 = buf, *p2 = buf, ubuf[1 << 23], *u = ubuf; */

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
const int N = 5e5 + 5, M = 1e6 + 5;
array <int, N> fir;
array <int, M> to, nex, len;
int cnt;
void add(int x, int y, int z) {
	cnt++;
	nex[cnt] = fir[x];
	to[cnt] = y;
	len[cnt] = z;
	fir[x] = cnt;
}
array <int, N> s, fa;
array <double, N> f, g;
double calc(double p_A, double p_B) {
	return p_A + p_B - p_A * p_B;
}
double _calc(double a, double b) {
	return (a - b) / (1.0 - b);
}
void dfs1(int x) {
	f[x] = s[x] / 100.0;
	for (int i = fir[x]; i; i = nex[i]) {
		if (to[i] == fa[x]) continue;
		fa[to[i]] = x;
		dfs1(to[i]);
		f[x] = calc(f[x], f[to[i]] * len[i] / 100.0);
		/* f[x] = min(f[x], 1.00); */
	}
}
void dfs2(int x) {
	if (x == 1) g[x] = f[x];
	for (int i = fir[x]; i; i = nex[i]) {
		if (to[i] == fa[x]) continue;
		dfs2(to[i]);
		g[to[i]] = calc(_calc(g[x], f[to[i]]) * len[i] / 100.0, f[to[i]]);
	}
	/* if (g[x] > 1) g[x] = 1; */
}
int main() {
	int n = read();
	for (int i = 2; i <= n; i++) {
		int x = read(), y = read(), z = read();
		add(x, y, z);
		add(y, x, z);
	}
	for (int i = 1; i <= n; i++)
		s[i] = read();
	dfs1(1), dfs2(1);
	double ans = 0;
	/* for (int i = 1; i <= n; i++) */
		/* printf("%.6lf ", f[i]); */
	/* puts(""); */

	for (int i = 1; i <= n; i++)
		ans += g[i];
	printf("%.6lf\n", ans);
	return 0;
}
/*
 *
 *
 *
 *
 *
 */

