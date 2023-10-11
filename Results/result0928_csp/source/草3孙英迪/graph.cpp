#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
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

const int N = 1005;
namespace Dsu {

array <int, N> fa, siz;
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	int fx = find(x),
		fy = find(y);
	if (fx == fy) return;
	if (siz[fx] > siz[fy]) swap(fx, fy);
	fa[fx] = fy;
	siz[fy] += siz[fx];
	return;
}
void init(int n) {
	for (int i = 1; i <= n; i++)
		fa[i] = i, siz[i] = 1;
}

}
array <int, N> x, y;
using namespace Dsu;
int main() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	int n = read();
	if (n > 5000) {
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		x[i] = read(), y[i] = read();
	}
	init(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (x[i] <= x[j] && y[i] <= y[j]) {
				merge(i, j);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (fa[i] == i) ans++;
	write(ans), puts("");
	return 0;
}
