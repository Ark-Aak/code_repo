#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
using namespace std;
#ifdef ONLINE_JUDGE

#define getchar () (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
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
const int N = 1e5 + 5;
array <int, N> s;
int main() {
	freopen("easiest.in", "r", stdin);
	freopen("easiest.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
		s[i] = read();
	while (m--) {
		int op = read(), l1 = read(), r1 = read(), l2 = read(), r2 = read();
		int ans = l2 - l1, tp = s[r2];
		for (int i = r2 + 1; i <= r1; i++) {
			if (s[i] > tp) tp = s[i];
			else ans++;
		}
		write(ans), puts("");
	}
	return 0;
}
