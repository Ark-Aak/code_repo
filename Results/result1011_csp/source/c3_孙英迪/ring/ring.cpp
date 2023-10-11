#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <ctime>
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
int ans;
array <int, 21> s, vis;
void dfs(int step, int n) {
	/* write(step), puts(""); */

	if (step == n) {
		bool flg = 0;
		array <int, 21> s = ::s, idx;
		for (int i = 1; i <= n; i++)
			idx[s[i]] = i;
		for (int i = 1; i <= n; i++) {
			//第i次操作
			if (idx[i] == 1) {
				int minn = min(s[n], s[2]),
					maxn = max(s[n], s[2]);
				if (minn < i && i < maxn) flg = 1;
				swap(s[n], s[2]);
				swap(idx[s[n]], idx[s[2]]);
			}
			else if (idx[i] == n) {
				int minn = min(s[n - 1], s[1]),
					maxn = max(s[n - 1], s[1]);
				if (minn < i && i < maxn) flg = 1;
				swap(s[n - 1], s[1]);
				swap(idx[s[n - 1]], idx[s[1]]);
			}
			else {
				int minn = min(s[idx[i] - 1], s[idx[i] + 1]),
					maxn = max(s[idx[i] - 1], s[idx[i] + 1]);
				if (minn < i && i < maxn) flg = 1;
				swap(s[idx[i] - 1], s[idx[i] + 1]);
				swap(idx[s[idx[i] - 1]], idx[s[idx[i] + 1]]);
			}
		}
		ans += flg;
		if (!flg) {
			/* for (int i = 1; i <= n; i++) */
				/* write(::s[i]), putchar(32); */
			/* puts(""); */
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		s[step + 1] = i;
		dfs(step + 1, n);
		vis[i] = 0;
	}
}
const int N = 2e4 + 5;
array <int, N> fac;
int main() {
	freopen("ring.in", "r", stdin);
	freopen("ring.out", "w", stdout);
	int n = read(), mod = read();
	fac[0] = 1;
	for (int i = 1; i <= 2e4; i++)
		fac[i] = fac[i - 1] * i % mod;
	/* if (n == 10) write(fac[10] - 79360), puts(""); */
	if (n & 1) write(fac[n] % mod), puts("");
	else dfs(0, n), write(ans % mod), puts("");
	/*
	for (int i = 2; i <= n; i++) {
		while (!(n % i))
			n /=i, write(i), putchar(32);
	}
	puts("");
	return 0;
	*/
	/* dfs(0, n); */
	/* write(ans), puts(""); */
	/* cout << clock() << endl; */
	return 0;
}
