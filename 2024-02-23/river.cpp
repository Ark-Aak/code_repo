#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

const int MAXN = 5e3 + 5;
int T, n, m, a[MAXN], b[MAXN], c[MAXN], t[MAXN];
int odd[MAXN], even[MAXN], cnt[MAXN], fa[MAXN], ch[MAXN];
vector <int> G[MAXN];
bool vis[MAXN], col[MAXN];
int x = 0, ocnt;

void dfs(int u) {
	for (auto v : G[u]) {
		if (v != fa[u] && v != x) {
			if (fa[v]) {
				if (vis[v]) continue;
				if (col[v] != col[u]) {
					odd[u]++;
					odd[ch[v]]--;
				}
				else {
					even[u]++;
					even[ch[v]]--;
					cnt[u]++;
					cnt[fa[v]]--;
					++ocnt;
				}
				continue;
			}
			col[v] = col[u] ^ 1;
			fa[v] = u;
			ch[u] = v;
			dfs(v);
			odd[u] += odd[v];
			even[u] += even[v];
			cnt[u] += cnt[v];
		}
	}
	vis[u] = 1;
}

void solve() {
	n = read(), m = read();
	memset(t, 0, sizeof t);
	rep (i, 1, m) {
		a[i] = read(), b[i] = read(), c[i] = read();
		t[a[i]]++, t[b[i]]++, t[c[i]]++;
	}
	x = 0;
	rep (i, 1, n) {
		if (t[i] == m) {
			if (x) x = -1;
			else x = i;
		}
	}
	if (x == -1) return puts("yes"), void();
	if (x == 0) return puts("no"), void();
	rep (i, 1, n) vector <int>().swap(G[i]);
	rep (i, 1, m) {
		if (a[i] == x && b[i] != c[i]) G[b[i]].push_back(c[i]), G[c[i]].push_back(b[i]);
		if (b[i] == x && a[i] != c[i]) G[a[i]].push_back(c[i]), G[c[i]].push_back(a[i]);
		if (c[i] == x && a[i] != b[i]) G[a[i]].push_back(b[i]), G[b[i]].push_back(a[i]);
	}
	bool can = 0;
	bool flg = 0;
	for (x = 1; x <= n; x++) {
		flg = 0;
		memset(fa, 0, sizeof fa);
		memset(odd, 0, sizeof odd);
		memset(vis, 0, sizeof vis);
		memset(cnt, 0, sizeof cnt);
		memset(even, 0, sizeof even);
		ocnt = 0;
		rep (i, 1, n) if (x != i && !fa[i]) fa[i] = n + 1, dfs(i);
		if (!ocnt) { flg = 1; break; }
		rep (i, 1, n) {
			if (cnt[i] == ocnt) {
				can = 1;
				for (auto v : G[i]) {
					if (fa[v] == i) if (odd[v] && even[v]) {
						can = 0;
						break;
					}
				}
				if (can) { flg = 1; break; }
			}
		}
		if (flg) break;
	}
	if (flg) puts("yes");
	else puts("no");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("river.in", "r", stdin);
	freopen("river.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
