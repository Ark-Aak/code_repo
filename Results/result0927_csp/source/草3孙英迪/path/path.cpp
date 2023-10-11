#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
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
const int N = 405, inf = 1e18;
array <array <int, N>, N> f;
array <int, N> s;
signed main() {
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	for (int i = 0; i < N; i++)
		f[i].fill(inf);
	f[0][0] = 0;
	int n = read(), m = read() + 1;
	for (int i = 1; i <= n; i++)
		s[i] = read();
	int ans = inf;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int maxn = 0, sumn = 0;
			for (int k = i; k >= 1; k--) {
				maxn = max(maxn, s[k]);
				sumn += s[k];
				f[i][j] = min(f[k - 1][j - 1] + (maxn * (i - k + 1) - sumn), f[i][j]);
				/* ans = min(ans, f[i][j]); */
			}
			/* write(f[i][j]), putchar(32); */
		}
		/* puts(""); */
	}
	write(f[n][m]), puts("");
	return 0;
}
