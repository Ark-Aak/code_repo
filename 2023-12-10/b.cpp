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
int n, m, s, p;

vector <int> G[MAXN];
queue <int> q;
int dis[MAXN], tp[MAXN], cnt;

int ans;

int sum = 0;
int to[MAXN];

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

int vis[MAXN], f[MAXN];

void bfs(int s) {
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	rep (i, 1, n) f[i] = i;
	for (auto v : G[s]) {
		dis[v] = min(dis[v], dis[s] + 1);
		--tp[v];
		++vis[v];
		if (!tp[v]) q.push(v);
	}
	while (q.size()) {
		int t = q.front();
		q.pop();
		if (vis[t] <= 1) ans = (ans + p - dis[f[t]]) % MOD;
		for (auto v : G[t]) {
			dis[v] = min(dis[v], dis[t] + 1);
			if (vis[v] && f[t] != f[v]) {
				f[v] = v, ++vis[v];
			}
			if (!vis[v]) {
				++vis[v];
				if (vis[t] <= 1) f[v] = f[t];
			}
			--tp[v];
			if (!tp[v]) q.push(v);
		}
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
#endif
	read(n), read(m), read(s), read(p);
	rep (i, 1, m) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		++tp[v];
	}
	bfs(s);
	print(ans * qpow(n, MOD - 2, MOD) % MOD);
	return 0;
}
