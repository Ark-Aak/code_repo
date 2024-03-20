#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MOD = 1e9 + 7;
int n, m, c, ans;

vector <pii> aak;
bool svash[105], vig[105];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void dfs(int step, int cnt) {
	if (step > m) {
		ans = (ans + qpow(c, cnt)) % MOD;
		return;
	}
	svash[step] = 0;
	dfs(step + 1, cnt);
	if (vig[aak[step].ec] || vig[aak[step].fb]) return;
	if ((cnt + 1) > n / 2) return;
	vig[aak[step].ec] = vig[aak[step].fb] = 1;
	svash[step] = 1;
	dfs(step + 1, cnt + 1);
	vig[aak[step].ec] = vig[aak[step].fb] = 0;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("dfs.in", "r", stdin);
	freopen("dfs.out", "w", stdout);
#endif
#endif
	aak.push_back(make_pair(0, 0));
	n = read(), m = read(), c = read();
	rep (i, 1, m) {
		int u, v;
		u = read(), v = read();
		aak.push_back(dl(u, v));
	}
	dfs(1, 0);
	print(ans), putchar(10);
	return 0;
}
