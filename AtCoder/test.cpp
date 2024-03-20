#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <cmath>
#include <set>
#define int long long
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

const int N = 1e3 + 5;

array <int, N> s;

int pow_(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans *= a;
		a *= a, b >>= 1;
	}
	return ans;
}

signed main() {
	/* freopen("out.txt", "w", stdout); */
	int h = read(), w = read(), n = read();
	pii tp0(h, w);
	for (int i = 1; i <= n; i++)
		s[i] = pow_(2, read());
	sort(s.begin() + 1, s.begin() + 1 + n, greater <int> ());
	multiset <pii, less <pii> > isl;
	isl.insert(tp0);
	for (int i = 1; i <= n; i++) {
		bool flg = 0;
		for (auto it = isl.begin(); it != isl.end(); it++) {
			if (it -> fi < s[i] || it -> se < s[i]) continue;
			int x = it -> fi, y = it -> se;
			isl.erase(it);
			isl.insert(make_pair(x - s[i], s[i]));
			isl.insert(make_pair(x, y - s[i]));
			flg = 1;
			break;
		}
		if (!flg) return puts("No"), 0;
	}
	puts("Yes");
	return 0;
}
