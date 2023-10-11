#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <vector>
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
const int N = 5e5 + 5, M = 1e6 + 5;
array <int, N> fir;
array <int, M> nex, to;
int cnt;
void add(int x, int y) {
	cnt++;
	nex[cnt] = fir[x];
	to[cnt] = y;
	fir[x] = cnt;
}
array <int, N> siz;
int dfs(int x, int fa) {
	siz[x] = 1;
	int ans = 0;
	for (int i = fir[x]; i; i = nex[i]) {
		if (to[i] == fa) continue;
		ans += dfs(to[i], x);
		siz[x] += siz[to[i]];
	}
	for (int i = fir[x]; i; i = nex[i]) {
		if (to[i] == fa) continue;
		ans += siz[to[i]] * (siz[x] - siz[to[i]]) * x;
	}
	ans += siz[x] * x;
	return ans;
}
void sub1(int n) {
	for (int i = 1; i <= n; i++)
		write(dfs(i, 0)), putchar(32);
	puts("");
}
array <int, N> idx;
int _cnt = 0;
void dfs_(int x, int fa) {
	_cnt++;
	idx[_cnt] = x;
	for (int i = fir[x]; i; i = nex[i]) {
		if (to[i] == fa) continue;
		dfs_(to[i], x);
	}
}
array <int, N> prl, prr;
array <int, N> cur;
void sub2(int n) {
	vector <int> isl;
	for (int i = 1; i <= n; i++) {
		int tp = 0;
		for (int j = fir[i]; j; j = nex[j])
			tp++;
		if (tp == 1) isl.push_back(i);
	}
	dfs_(isl[0], 0);
	for (int i = 1; i <= n; i++)
		prl[i] = prl[i - 1] + ((i - 1) * 2 + 1) * idx[i];
	for (int i = n; i >= 1; i--)
		prr[i] = prr[i + 1] + ((n - i) * 2 + 1) * idx[i];
	for (int i = 1; i <= n; i++)
		cur[idx[i]] = prl[i - 1] + prr[i + 1] + idx[i] * ((n - i) * i + (i - 1) * (n - i + 1) + n);
	for (int i = 1; i <= n; i++)
		write(cur[i]), putchar(32);
	puts("");
}
signed main() {
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);
	int n = read();
	for (int i = 2; i <= n; i++) {
		int x = read(), y = read();
		add(x, y), add(y, x);
	}
	/* sub1(n); */
	/* sub2(n); */
	if (n <= 5000) sub1(n);
	else sub2(n);
	return 0;
}
