#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <cmath>
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
const int mod = 147744151;
int pow_(int x, int k, int p) {
	int ans = 1;
	while (k) {
		if (k & 1) ans = ans * x % p;
		x = x * x % p;
		k >>= 1;
	}
	return ans;
}
signed main() {
	freopen("greedy.in", "r", stdin);
	freopen("greedy.out", "w", stdout);
	int n = read(), k = read() - 1;
	if (!k) write(n - 1), puts(""), exit(0);
	int tp = 0;
	while (k-- && n > 2) {
		n = sqrt(2 * n);
		tp++;
	}
	write(tp * n % mod), puts("");
	return 0;
}
