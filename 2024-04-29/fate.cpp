#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
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

const int MAXN = 1e5 + 5;
int _T;
int n, m;
vector <int> G[MAXN];
int dis[2][MAXN];
int val[MAXN], f1[MAXN], f2[MAXN];
int fa[MAXN];
const int mask = 0b10101010101;

int shift(int w) {
    w ^= mask;
	w ^= w << 13;
	w ^= w >> 7;
    w ^= w << 17;
	w ^= mask;
	return w;
}

int Hash(int x, int fa) {
    int res = 1;
	if (dis[0][x] == dis[1][x]) return val[x];
    for (auto v : G[x]) {
		if (v != fa) {
			res += shift(Hash(v, x));
		}
	}
    return res;
}

void bfs(int id, int S) {
	memset(dis[id], 0, sizeof dis[id]);
    queue<int> q;
	q.push(S);
	dis[id][S] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int v : G[x]) {
			if (!dis[id][v]) {
            	dis[id][v] = dis[id][x] + 1;
				q.push(v);
			}
		}
    }
}

vector <pii> del;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

bool check(int r0, int r1) {
	for (auto [u, v] : del) G[u].push_back(v), G[v].push_back(u);
	del.clear();
	bfs(0, r0), bfs(1, r1);
	int cnt = m - n + 2;
	rep (i, 1, n) {
		if (dis[0][i] == dis[1][i]) {
			if (G[i].size() != 2) return 0;
			cnt--;
			val[i] = rnd();
		}
	}
	if (cnt) return 0;
	return Hash(r0, 0) == Hash(r1, 0);
}

void rm(int x, int y) {
	for (auto &v : G[x]) {
		if (v != y) continue;
		swap(v, G[x].back());
		G[x].pop_back();
		break;
	}
	for (auto &v : G[y]) {
		if (v != x) continue;
		swap(v, G[y].back());
		G[y].pop_back();
		break;
	}
	del.push_back({ x, y });
}

bool fl = 0;

void d(int u, int to) {
	f1[u] = 1;
	rm(u, fa[u]);
	if (fa[u] != to) d(fa[u], to);
}

void dfs(int u) {
	for (auto v : G[u]) {
		if (v == fa[u]) continue;
		if (fa[v] && !fl) {
			d(u, v);
			rm(u, v);
			fl = 1;
			f1[v] = 1;
		}
		else if (!fa[v]) fa[v] = u, dfs(v);
	}
}

vector <int> tp;

void mark(int u) {
	if (f1[u]) tp.push_back(u);
	f2[u] = 1;
	for (auto v : G[u]) if (!f2[v]) mark(v);
}

bool VIS[MAXN];

void dfs1(int u) {
	if (VIS[u]) return;
	VIS[u] = 1;
	for (auto v : G[u]) dfs1(v);
}

void solve() {
	n = read(), m = read();
	del.clear();
	tp.clear();
	fl = 0;
	memset(val, 0, sizeof val);
	memset(f1, 0, sizeof f1);
	memset(f2, 0, sizeof f2);
	memset(fa, 0, sizeof fa);
	memset(VIS, 0, sizeof VIS);
	rep (i, 1, n) G[i].clear();
	rep (i, 1, m) {
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs1(1);
	rep (i, 1, n) if (!VIS[i]) return puts("NO"), void();
	int F = 0;
	rep (i, 1, n) F += G[i].size() == 1;
	if (F == 2) {
		int a = 0, b = 0;
		rep (i, 1, n) if (G[i].size() == 1) {
			if (a) b = i;
			else a = i;
		}
		return puts(check(a, b) ? "YES" : "NO"), void();
	}
	if (F) return puts("NO"), void();
	fa[1] = -1;
	dfs(1);
	rep (i, 1, n) {
		if (f1[i] || f2[i]) continue;
		mark(i);
		if (tp.size() != 2 || !check(tp[0], tp[1])) return puts("NO"), void();
		return puts("YES"), void();
	}
	if (!fl || (n & 1)) return puts("NO"), void();
	rep (i, 1, n) if (G[i].size()) return puts("NO"), void();
	puts("YES");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("fate.in", "r", stdin);
	freopen("fate.out", "w", stdout);
#endif
#endif
	_T = read();
	while (_T --> 0) solve();
	return 0;
}
