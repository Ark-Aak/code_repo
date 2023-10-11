#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <tuple>
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
const int N = 2e5 + 5;
array <tuple <int, int, int>, N> isl;
namespace uni {

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
}
void init(int n) {
	for (int i = 1; i <= n; i++)
		siz[fa[i] = i] = 1;
}

}
signed main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	int n = read();
	uni::init(n * 2);
	for (int i = 1; i <= n; i++) {
		get <0>(isl[i]) = read();
		int x_1 = read(), y_1 = read(), x_2 = read(), y_2 = read();
		uni::merge(x_1, y_1), uni::merge(x_2, y_2);
		get <1>(isl[i]) = uni::find(x_1), get <2>(isl[i]) = uni::find(x_2);
	}
	/* int ans = 0; */
	/* for (int i = 1; i <= 2 * n; i++) { */
		/* if (i == uni::find(i)) ans++; */
	/* } */
	/* write(ans), puts(""); */
	sort(isl.begin() + 1, isl.begin() + 1 + n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		/* write(uni::find(get <1>(isl[i]))), putchar(32); */
		/* write(uni::find(get <2>(isl[i]))), puts(""); */
		if (uni::find(get <1>(isl[i])) ==
			uni::find(get <2>(isl[i]))) continue;
		uni::merge(get <1>(isl[i]), get <2>(isl[i]));
		ans += get <0>(isl[i]);
	}
	write(ans), puts("");
	return 0;
}
