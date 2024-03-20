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

const int MAXN = 1e6 + 5;

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

int T, n, l[MAXN], r[MAXN], k[MAXN];
bool uk[MAXN], vis[MAXN];

queue <int> q;

namespace seg {

	int head[MAXN << 2], cnt;
	int lst[MAXN << 2], nxt[MAXN << 2], prev[MAXN << 2], val[MAXN << 2];
	vector <pii> pt[MAXN << 2];

	void build(int x, int L, int R) {
		head[x] = lst[x] = ++cnt;
		nxt[cnt] = prev[cnt] = val[cnt] = 0;
		if (L == R) return pt[L].clear(), void();
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
	}

	void insert(int x, int L, int R, int l, int r, int p) {
		if (L > r || R < l) return;
		if (l <= L && R <= r) {
			val[++cnt] = p;
			pt[p].push_back(dl(cnt, x));
			nxt[lst[x]] = cnt;
			prev[cnt] = lst[x];
			lst[x] = cnt;
			nxt[cnt] = 0;
			return;
		}
		insert(ls(x), L, mid, l, r, p);
		insert(rs(x), mid + 1, R, l, r, p);
	}

	void _remove(int x) {
		for (auto [id, X] : pt[x]) {
			prev[nxt[id]] = prev[id];
			nxt[prev[id]] = nxt[id];
			if (!nxt[id]) lst[X] = prev[id];
		}
	}

	void remove(int x, int L, int R, int p) {
		for (int i = nxt[head[x]]; i; i = nxt[i]) {
			k[val[i]]--;
			if (k[val[i]] == 0) {
				vis[val[i]] = 1;
				q.push(val[i]);
				_remove(val[i]);
			}
		}
		if (L == R) return;
		if (p <= mid) remove(ls(x), L, mid, p);
		else remove(rs(x), mid + 1, R, p);
	}
} // namespace seg

int pre[MAXN];

void solve() {
	int ans = 0;
	seg::cnt = 0;
	memset(vis, 0, sizeof vis);
	memset(uk, 0, sizeof uk);
	n = read();
	const int B = sqrt(n);
	rep(i, 1, n) l[i] = read(), r[i] = read(), k[i] = read();
	seg::build(1, 1, n);
	rep (__i, 1, n / B + 1) {
		rep (i, 1, n) pre[i] = pre[i - 1] + uk[i];
		rep (i, 1, n) {
			if (vis[i]) continue;
			int pval = k[i] - pre[r[i]] + pre[l[i] - 1];
			if (pval > B) continue;
			vis[i] = 1; k[i] = pval;
			if (pval <= 0) q.push(i);
			else seg::insert(1, 1, n, l[i], r[i], i);
		}
		while (q.size()) {
			int x = q.front(); q.pop();
			uk[x] = 1;
			ans++;
			seg::remove(1, 1, n, x);
		}
	}
	print(ans); putchar(10);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
