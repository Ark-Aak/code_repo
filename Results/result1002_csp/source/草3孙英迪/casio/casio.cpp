#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <bitset>
#include <vector>
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
const int N = 3e7 + 5;
vector <int> p;
array <int, N> minp;
bitset <N> vis;
void Euler(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			p.push_back(i);
			minp[i] = i;
		}
		for (int j = 0; j < p.size() && i * p[j] <= n; j++) {
			vis[i * p[j]] = 1;
			minp[i * p[j]] = p[j];
			if (i % p[j] == 0) {
				minp[i] = p[j];
				break;
			}
		}
	}
}
int main() {
	freopen("casio.in", "r", stdin);
	freopen("casio.out", "w", stdout);
	Euler(3e7);
	int T = read(), P = read();
	while (T--) {
		int n = read();
		int pos = lower_bound(p.begin(), p.end(), n) - p.begin();
		for (int i = n; i <= p[pos]; i++) {
			if (minp[i] <= P) continue;
			write(i), puts("");
			break;
		}
		if (p[pos] <= P)
			write(p[pos]), puts("");
	}
	return 0;
}
