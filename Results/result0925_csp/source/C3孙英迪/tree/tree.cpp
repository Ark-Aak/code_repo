#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <vector>
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
const int N = 4e5 + 5, M = 8e5 + 5, mod = 1e9 + 7;
array <int, N> fir;
array <int, M> nex, to;
int cnt;
void add(int x, int y) {
	cnt++;
	nex[cnt] = fir[x];
	to[cnt] = y;
	fir[x] = cnt;	
}
array <int, N> fa;
vector <pii> isl;
void dfs(int x) {
	if (fa[x]) isl.push_back(make_pair(min(x, fa[x]), max(x, fa[x])));
	for (int i = fir[x]; i; i = nex[i]) {
		if (to[i] == fa[x]) continue;
		fa[to[i]] = x;
		dfs(to[i]);
	}
}
bool cmp(pii a, pii b) {
	return a.se == b.se ? a.fi < b.fi : a.se < b.se;	
}
int pow_(int x, int k) {
	if (k == 1) return x;
	else return x * x % mod;	
}
int Mod(int &x) {
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;	
}
void Sub1(int n, int k) {
	dfs(1);
	sort(isl.begin(), isl.end(), cmp);
	int ans_ = 0;
	for (int i = 1; i <= n; i++) {
		int tp = 0, ans = 0;
		for (int j = i; j <= n; j++) {
			while (tp <= isl.size() && isl[tp].se <= j) {
				if (isl[tp].fi >= i) ans++, Mod(ans);
				tp++;
			}
			int it = (j - i + 1 - ans);
			ans_ += pow_(it, k), Mod(ans);
		}
	}
	write(ans_), puts("");
}
void Sub2(int n, int k) {
	dfs(1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += i * (n - i + 1) % mod;
		Mod(ans);
	}
	for (auto x : isl) {
		ans -= x.fi * (n - x.se + 1) % mod;
		Mod(ans);
	}
	write(ans), puts("");
}
array <int, N> fac;
void Sub3(int n, int k) {
	int pos = 0;
	for (int i = 1; i <= n; i++) {
		if (nex[fir[i]]) {
			pos = i;
			break;	
		}
	}
	dfs(pos);
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] + i * i % mod;
		Mod(fac[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (pos >= i) {
			ans += fac[pos - 1 - i + 1], Mod(ans);
			ans += n - pos + 1, Mod(ans);
		}
		else {
			ans += fac[n - i + 1], Mod(ans);	
		}
	}
	write(ans), puts("");
}
signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int n = read(), k = read();
	for (int i = 2; i <= n; i++) {
		int x = read(), y = read();
		add(x, y);
		add(y, x);	
	}
//	Sub3(n, k);
//	return 0;
	if (n <= 5000 && k == 2) Sub1(n, k);
	else if (k == 1) Sub2(n, k);
	else Sub3(n, k);
	return 0;	
}
