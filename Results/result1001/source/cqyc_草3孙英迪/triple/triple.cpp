#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <tuple>
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
array <int, 5> s, t, isl;
void solve() {
	for (int i = 1; i <= 3; i++)
		s[i] = read();
	for (int i = 1; i <= 3; i++)
		t[i] = read();
	for (int i = 1; i <= 3; i++)
		isl[i] = t[i] - s[i];
	sort(isl.begin() + 1, isl.begin() + 4);
	if (!isl[3]) puts("0");
	else if ((isl[1] == isl[2] && isl[2] == isl[3]) || (s[1] && s[2] && s[3] && isl[1] % s[1] == 0 && isl[2] % s[2] == 0 && isl[3] % s[3] == 0 && isl[1] / s[1] == isl[2] / s[2] && isl[2] / s[2] == isl[3] / s[3]) || (isl[2] == isl[3] && !isl[1]) || (!isl[1] && !isl[2]) || (!t[1] && !t[2] && !t[3])) puts("1");
	else if ((!t[1] && !t[2]) || (!t[1] && !t[3]) || (!t[2] && !t[3]) || (isl[1] == isl[2]) || (isl[2] == isl[3]) || !isl[1]) puts("2");
	else puts("3");
}
int main() {
	/* freopen("triple2.in", "r", stdin); */
	/* freopen("triple.out", "w", stdout); */
	int T = read();
	while (T--) {
		/* cerr << T << endl; */
		solve();
	}
	return 0;
}
