#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <bitset>
#define pii pair <int, int>
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
#define fi first
#define se second
const int N = 2005;
array <pii, N> s;
int main() {
	int n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++)
		s[i].fi = read(), s[i].se = read();
	int ans = 0;
	for (int T = 0; T < 1 << m; T++) {
		int idx = 0;
		for (int i = 1; i <= m; i++) {
			if (T & (1 << (i - 1))) {
				idx++;
			}
		}
		if (idx != k) continue;
		bitset <N> vis = 0;
		for (int i = 1; i <= m; i++) {
			if (!(T & (1 << (i - 1)))) continue;
			for (int j = s[i].fi; j <= s[i].se; j++)
				vis[j] = 1;
		}
		idx = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) continue;
			idx++;
		}
		/* if (idx == 9) { */
			/* for (int i = 1; i <= n; i++) */
				/* write(vis[i]), putchar(32) */
		/* } */
		ans = max(ans, idx);
	}
	write(ans), puts("");
	return 0;
}
