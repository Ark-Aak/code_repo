#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
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
int n, siz[MAXN], sum[MAXN], ans[MAXN], fans, cnt;
vector <int> G[MAXN];
bitset <MAXN> vis;

void dfs(int u, int fa) {
	siz[u] = 1; sum[u] = u;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
		sum[u] += u * 2 * (siz[v] * (siz[u] - 1));
		siz[u] += siz[v];
		sum[u] += sum[v];
	}
	sum[u] += u * 2 * (siz[u] - 1);
}

void dfs1(int u, int fa) {
	siz[u] = 1; sum[u] = u;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs1(v, u);
		sum[u] += u * 2 * (siz[v] * (siz[u] - 1));
		siz[u] += siz[v];
		//sum[u] += sum[v];
	}
	sum[u] += u * 2 * (siz[u] - 1);
}

void solve(int u, int fa) {
	fans -= sum[fa] + sum[u];
	int osiz = siz[fa] - 1 - siz[u];
	sum[fa] -= osiz * siz[u] * 2 * fa;
	sum[u] += osiz * siz[u] * 2 * u;
	sum[fa] -= siz[u] * 2 * fa;
	sum[u] += siz[u] * 2 * u;
	int tsiz = siz[u];
	siz[u] = siz[fa];
	siz[fa] -= tsiz;
	fans += sum[fa] + sum[u];
	ans[u] = fans;
	for (auto v : G[u]) {
		if (v == fa) continue;
		solve(v, u);
	}
	fans -= sum[fa] + sum[u];
	siz[fa] += tsiz;
	siz[u] = tsiz;
	sum[u] -= siz[u] * 2 * u;
	sum[fa] += siz[u] * 2 * fa;
	sum[u] -= osiz * siz[u] * 2 * u;
	sum[fa] += osiz * siz[u] * 2 * fa;
	fans += sum[fa] + sum[u];
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n - 1) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	if (n <= 4000) {
		rep (i, 1, n) {
			dfs(i, 0);
			print(sum[i]), putchar(32);
		}
		return 0;
	}
	dfs1(1, 0);
	rep (i, 1, n) fans += sum[i];
	ans[1] = fans;
	for (auto v : G[1]) solve(v, 1);
	rep (i, 1, n) print(ans[i]), putchar(32);
	return 0; 
}
