#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#define int long long
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
char strbuf[5];
void solve() {
	scanf("%s", strbuf);
	string s = strbuf;
	int n = read();
	if ((s[0] == s[1] && s[1] == s[2]) || !n) {
		puts("1");
	}
	else if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) {
		if (n == 1) puts("7");
		else puts("8");
	}
	else {
		if (n == 1) puts("24");
		else puts("27");
	}
}
signed main() {
	freopen("device.in", "r", stdin);
	freopen("device.out", "w", stdout);
	int T = read();
	while (T--) solve();
	return 0;
}
