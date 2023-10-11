#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#define int long long
using namespace std;
/* #ifdef ONLINE_JUDGE */

/* #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++) */
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

const int N = 1e6 + 5;
namespace checker {

array <int, N> s;
int n;

bool check() {
	for (int l = 1; l <= n; l++) {
		for (int r = l + 1; r <= n; r++) {
			for (int l_ = r + 1; l_ <= n; l_++) {
				for (int r_ = l_ + 1; r_ <= n; r_++) {
					if (r - l + 1 != r_ - l_ + 1) continue;
					write(l), putchar(32);
					write(r), putchar(32);
					write(l_), putchar(32);
					write(r_), puts("");
					for (int i = 0; l + i <= r; i++) {
						if (s[l + i] == s[l_ + i])
							return false;
					}
				}
			}
		}
	}
	return true;
}
void init(array <int, N> tmp, int n_) {
	s = tmp;
	n = n_;
	if (check()) puts("AC");
	else puts("WA");
}

}
array <int, N> s;
signed main() {
	freopen("kel.in", "r", stdin);
	freopen("kel.out", "w", stdout);
	/* checker::init(s, n); */
	int n = read(), L = read(), R = read();
	if ((R - L + 1) * 2 < n) {
		puts("Shinomiya");
		return 0;
	}
	int tp = 0;
	for (int i = L; (i - L + 1) * 2 <= n; i++) {
		tp++, s[tp] = i;
		tp++, s[tp] = i;
	}
	if (n & 1) s[n] = n / 2 + L;
	for (int i = 1; i <= n; i++)
		write(s[i]), puts("");
	return 0;
}
