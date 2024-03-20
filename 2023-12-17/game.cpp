#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 1e6 + 5;
const int MOD = 998244353;
int n, k, v;
int pw[MAXN], cnt[MAXN];

struct G {
	vector <int> gx[MAXN], gy[MAXN];
	int SG[MAXN], deg[MAXN];

	void add(int u, int v) {
		if (u > v) swap(u, v);
		deg[u]++;
		gx[v].emplace_back(u);
		gy[u].emplace_back(v);
	}

	void calc(int u) {
		for (auto v : gy[u]) cnt[SG[v]] = 1;
		SG[u] = 0;
		while (cnt[SG[u]]) SG[u]++;
		for (auto v : gy[u]) cnt[SG[v]] = 0;
	}

	void sg() {
		queue <int> q;
		rep (i, 1, n) if (deg[i] == 0) q.push(i);
		while (q.size()) {
			int tp = q.front(); q.pop();
			for (auto v : gx[tp]) {
				deg[v]--;
				if (deg[v] == 0) {
					calc(v);
					q.push(v);
				}
			}
		}
	}
} g[10];

int f[10][MAXN];

signed main() {
	read(n), read(k), read(v);
	pw[0] = 1;
	rep (i, 1, n) pw[i] = pw[i - 1] * v % MOD;
	rep (i, 1, k) {
		int m; read(m);
		for (int j = 1, u, v; j <= m; j++) {
			read(u), read(v);
			g[i].add(u, v);
		}
	}
	rep (i, 1, k) g[i].sg();
	f[1][0] = 1;
	rep (i, 1, k) {
		rep (j, 0, 400) {
			rep (g, 1, n) {
				f[i + 1][j ^ ::g[i].SG[g]] += f[i][j] * pw[g];
				f[i + 1][j ^ ::g[i].SG[g]] %= MOD;
			}
		}
	}
	print(f[k + 1][0]);
	return 0;
}
