#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <random>
#include <ctime>
using namespace std;
/* #ifdef ONLINE_JUDGE */

/* #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1== p2 ) ? EOF : * po */
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
int main() {
	mt19937 rnd(time(0) + 'c' + 'n' + 'm');
	int n = 10, m = 7, k = 5;
	write(n), putchar(32);
	write(m), putchar(32);
	write(k), puts("");
	for (int i = 1; i <= m; i++) {
		int l = rnd() % n + 1,
			r = rnd() % n + 1;
		if (l > r) swap(l, r);
		write(l), putchar(32);
		write(r), puts("");
	}

	return 0;
}
