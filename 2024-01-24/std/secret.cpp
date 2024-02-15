#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-')
			f = -1;
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
	if (x < 0)
		x = (~x + 1), putchar('-');
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 505050, MAXK = MAXN * 3, MAXM = MAXK * 2;
const int INF = 0x3f3f3f3f;
int cnt, dfn[MAXK], low[MAXK], tp, st[MAXK], sct, scc[MAXK];
vector <int> vc[MAXK], G[MAXN];

inline void add(int x, int y) {
	G[x].push_back(y);
}

inline void tarjan(int x) {
	dfn[x] = low[x] = ++cnt, st[++tp] = x;
	for (auto y : G[x]) {
		if (!dfn[y]) tarjan(y), low[x] = min(low[x], low[y]);
		else if (!scc[y]) low[x] = min(low[x], dfn[y]);
	}
	if (dfn[x] == low[x]) {
		++sct;
		do {
			vc[scc[st[tp]] = sct].push_back(st[tp]);
		} while (st[tp--] != x);
	}
}

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

int a[MAXN];
ll s[MAXM], v[MAXM];

inline void merge(int x) {
	s[x] = s[ls(x)] + s[rs(x)];
	v[x] = min(v[ls(x)] + s[rs(x)], (ll) v[rs(x)]);
}

inline void build(int x, int l, int r) {
	if (l == r) {
		s[x] = max(0ll, -a[l]);
		v[x] = INF;
		return;
	}
	int d = (l + r) >> 1;
	build(ls(x), l, d);
	build(rs(x), d + 1, r);
	merge(x);
}

inline void update(int x, int l, int r, int p, ll val) {
	if (l == r) {
		s[x] += val;
		v[x] += val;
		return;
	}
	int d = (l + r) >> 1;
	if (p <= d) update(ls(x), l, d, p, val);
	else update(rs(x), d + 1, r, p, val);
	merge(x);
}

pair <int, int> query(int x, int l, int r, int p) {
	if (p <= l)
		return make_pair(s[x], v[x]);
	int d = (l + r) >> 1;
	if (d <= p)
		return query(rs(x), d + 1, r, p);
	pair <int, int> L = query(ls(x), l, d, p);
	pair <int, int> R = query(rs(x), d + 1, r, p);
	return make_pair(L.first + R.first, min(L.second + R.first, R.second));
}

#undef ls
#undef rs

int p[MAXK], q[MAXK], mp[MAXK], mq[MAXK];
vector <int> o[MAXN];

inline void solve() {
	int n;
	cin >> n;
	int m = (n << 1) + 2;
	ll sum = 0ll;
	rep (i, 1, n) cin >> a[i], G[i].clear();
	rep (i, 1, n) {
		int tmp;
		cin >> tmp;
		a[i] -= tmp;
	}
	rep (i, 1, n) cin >> p[i];
	rep (i, 1, n) cin >> q[i + 1];
	a[++n] = 0, q[1] = 0, p[n] = n + 1;
	_rep (i, n, 1) a[i] = a[i] - a[i - 1];
	add(n + 1, 1);
	rep (i, 2, n) add(n + i, n + i - 1), add(n + i, i);
	add(m + n, n);
	_rep (i, n - 1, 1) add(m + i, m + i + 1), add(m + i, i);
	rep (i, 1, n) {
		if (q[i])
			add(i, q[i] + n);
		if (p[i] <= n)
			add(i, p[i] + m);
		p[i + n] = p[i + m] = INF, q[i + n] = q[i + m] = 0;
	}
	m += n;
	rep (i, 1, m) if (!dfn[i]) tarjan(i);
	rep (k, 1, sct) {
		mp[k] = INF, mq[k] = 0;
		for (auto x : vc[k]) {
			mp[k] = min(mp[k], p[x]), mq[k] = max(mq[k], q[x]);
			for (auto y : G[x]) {
				mp[k] = min(mp[k], p[y]), mq[k] = max(mq[k], q[y]);
			}
		}
		for (auto x : vc[k])
			p[x] = mp[k], q[x] = mq[k];
	}
	rep (i, 1, n) if (a[i] > 0) o[q[i]].push_back(i);
	a[++n] = 0, build(1, 1, n);
	int flag = 1;
	rep (i, 0, n - 1) {
		if (a[i] < 0)
			sum -= a[i];
		for (auto j : o[i])
			update(1, 1, n, p[j], -a[j]);
		if (o[i].size() && (sum + query(1, 1, n, i + 1).second) < 0) {
			flag = 0, i = n;
		}
	}
	puts(flag ? "YES" : "NO");
	rep (i, 1, m) scc[i] = dfn[i] = 0;
	rep (i, 1, sct) vc[i].clear();
	rep (i, 0, n) o[i].clear();
	tp = sct = cnt = 0;
}

signed main() {
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
