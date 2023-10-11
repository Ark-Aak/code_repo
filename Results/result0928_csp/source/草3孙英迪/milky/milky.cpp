#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#define int unsigned int
using namespace std;
#ifdef ONLINE_JUDGE

/* #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++) */
/* char buf[1 << 23], *p1 = buf, *p2 = buf, ubuf[1 << 23], *u = ubuf; */

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
const int N = 2005;
array <int, N> f;
array <int, 27> g;
char strbuf[N];
signed main() {
	freopen("milky.in", "r", stdin);
	freopen("milky.out", "w", stdout);
	scanf("%s", strbuf);
	string s = strbuf;
	int n = s.size();
	s = " " + s;
	int q = read();
	while (q--) {
		int l = read(), r = read();
		f.fill(0);
		g.fill(0);
		for (int i = r; i >= l; i--) {
			if (s[i] == 'y') {
				f[i] = 1, g[s[i] - 'a']++;
				continue;
			}
			if (s[i] == 'm') f[i] += g['i' - 'a'], g['m' - 'a'] += f[i];
			if (s[i] == 'i') f[i] += g['l' - 'a'], g['i' - 'a'] += f[i];
			if (s[i] == 'l') f[i] += g['k' - 'a'], g['l' - 'a'] += f[i];
			if (s[i] == 'k') f[i] += g['y' - 'a'], g['k' - 'a'] += f[i];
		}
		write(g['m' - 'a']), puts("");
	}
	return 0;
}
