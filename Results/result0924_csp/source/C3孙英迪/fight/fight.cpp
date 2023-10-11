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
const int N = 5005;
array <int, N> s;
namespace Sub1 {

void solve(int n, int x) {
	for (int i = 1; i <= n; i++)
		printf("%.10lf\n", 1.0 / n);
}

}
int main() {
	freopen("fight.in", "r", stdin);
	freopen("fight.out", "w", stdout);
	int n = read(), x = read();
	for (int i = 1; i < n; i++)
		s[i] = read();
	s[n] = x;
	bool flg = false;
	for (int i = 2; i <= n; i++) {
		if (s[i] != s[i - 1]) {
			flg = true;
			break;
		}
	}
	if (!flg) Sub1::solve(n, x);
	return 0;
}
