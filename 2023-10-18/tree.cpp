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
#define mp make_pair

const int MAXN = 1e5 + 5;
int n, m;
vector <pair <int, int> > G[MAXN];
int siz[MAXN], dep[MAXN], asiz;
int W[MAXN], V[MAXN], cnt, Ans;
int f[MAXN];

void siz_dep(int step, int u, int fa) {
	dep[u] = step;
	siz[u] = 1;
	for (auto x : G[u]) {
		int v = x.first;
		if (v == fa) continue;
		siz_dep(step + 1, v, u);
		siz[u] += siz[v];
	}
}

bitset <5005> vis[5005];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, n - 1) {
		int u, v, w;
		read(u), read(v), read(w);
		G[u].emplace_back(mp(v, w));
		G[v].emplace_back(mp(u, w));
	}
	siz_dep(1, 1, 1);
	rep (i, 1, n) {
		for (auto x : G[i]) {
			int u = i, v = x.first;
			if (dep[u] > dep[v]) swap(u, v);
			if (vis[u][v]) continue;
			vis[u][v] = 1;
			int S = siz[v];
			Ans += S * (n - S) * x.second;
			++cnt;
			W[cnt] = S * (n - S) * x.second;
			V[cnt] = S;
		}
	}
	rep (i, 1, cnt) {
		_rep (j, m, V[i]) {
			f[j] = max(f[j], f[j - V[i]] + W[i]);
		}
	}
	int ans = 0;
	rep (i, 0, m) ans = max(ans, f[i]);
	print(Ans - ans);
	return 0;
}
