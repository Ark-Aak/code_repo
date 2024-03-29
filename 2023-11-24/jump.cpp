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

const int MAXN = 200;
int n, m;
vector <int> G[MAXN];
vector <int> c[MAXN][MAXN];
int f[MAXN][MAXN];

void dfs(int u, int ori, int fa) {
	c[ori][u].emplace_back(u);
	for (auto v : G[u]) {
		if (v == fa) continue;
		c[ori][v] = c[ori][u];
		dfs(v, ori, u);
	}
}

bool flg = 1;
int qz[200005];
int sum[200005];

int lowbit(int x) {
	return x & -x;
}

void _add(int p, int val) {
	if (p == 0) return;
	while (p <= 200000) {
		sum[p] += val;
		p += lowbit(p);
	}
}

void add(int l, int r) {
	_add(l, 1), _add(r + 1, -1);
}

int _query(int p) {
	int res = 0;
	while (p) {
		res += sum[p];
		p -= lowbit(p);
	}
	return res;
}

int query(int l, int r) {
	return _query(r) - _query(l - 1);
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
#endif
#endif
	memset(f, 0x3f, sizeof f);
	read(n), read(m);
	rep (i, 1, n - 1) {
		int u, v;
		read(u), read(v);
		if (u + 1 != v) flg = 0;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
		if (n <= 200) f[u][v] = f[v][u] = 1;
	}
	//if (flg) {
	//	rep (i, 1, m) {
	//		int u, v;
	//		read(u), read(v);
//
	//	}
	//	return;
	//}
	rep (i, 1, n) dfs(i, i, 0);
	rep (i, 1, m) {
		int u, v;
		read(u), read(v);
		for (auto a : c[u][v]) {
			for (auto b : c[u][v]) {
				f[a][b] = f[b][a] = 1;
			}
		}
	}
	rep (i, 1, n) f[i][i] = 0;
	rep (k, 1, n) {
		rep (i, 1, n) {
			rep (j, 1, n) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	int q;
	read(q);
	while (q --> 0) {
		int u, v;
		read(u), read(v);
		print(f[u][v]), putchar(10);
	}
	return 0;
}