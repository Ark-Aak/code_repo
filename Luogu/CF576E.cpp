#include <bits/stdc++.h>

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

const int MAXN = 5e5 + 5, N = 2e5;
const int MAXK = 55;
int n, m, k, q, p[MAXN], a[MAXN], c[MAXN];

pair <int, int> e[MAXN];

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

stack <tuple <int, int, int> > s;

struct union_find {

	int fa[MAXN << 1], siz[MAXN << 1], id;

	void init(int _id) { id = _id; rep (i, 1, n) fa[i] = i, fa[i + n] = i + n; }
	int find(int x) {return x == fa[x] ? x : find(fa[x]); }

	void merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) return;
		if (siz[fx] > siz[fy]) swap(fx, fy);
		s.push(dk(id, fx, siz[fx] == siz[fy]));
		fa[fx] = fy, siz[fy] += siz[fx] == siz[fy];
	}

} uf[MAXK];

void _undo(tuple <int, int, int> op = s.top()) {
	s.pop();
	int id, x, y;
	tie(id, x, y) = op;
	uf[id].siz[uf[id].fa[x]] -= y;
	uf[id].fa[x] = x;
}

void undo(int t) { while ((int) s.size() > t) _undo(); }

namespace seg {

	vector <int> v[MAXN << 2];

	void insert(int x, int L, int R, int l, int r, int id) {
		if (l <= L && R <= r) return v[x].push_back(id), void();
		if (l <= mid) insert(ls(x), L, mid, l, r, id);
		if (r > mid) insert(rs(x), mid + 1, R, l, r, id);
	}

	void solve(int x, int L, int R, int t = s.size()) {
		for (auto id : v[x]) {
			int A = a[id], C = c[id], u = e[A].ec, v = e[A].fb;
			if (C) {
				uf[C].merge(uf[C].find(u), uf[C].find(v + n));
				uf[C].merge(uf[C].find(u + n), uf[C].find(v));
			}
		}
		if (L == R) {
			int A = a[L], C = c[L], u = e[A].ec, v = e[A].fb;
			if (uf[C].find(u) == uf[C].find(v)) puts("NO"), c[L] = p[A];
			else puts("YES"), p[A] = c[L];
		}
		else {
			solve(ls(x), L, mid);
			solve(rs(x), mid + 1, R);
		}
		undo(t);
	}
} // namespace seg

signed main() {
	n = read(), m = read(), k = read(), q = read();
	rep (i, 1, m) {
		e[i].ec = read(), e[i].fb = read();
		p[i] = q + 1;
	}
	rep (i, 1, q) a[i] = read(), c[i] = read();
	rep (i, 1, k) uf[i].init(i);
	_rep (i, q, 1) {
		if (i < p[a[i]] - 1) seg::insert(1, 1, q, i + 1, p[a[i]] - 1, i);
		p[a[i]] = i;
	}
	memset(p, 0, sizeof p);
	seg::solve(1, 1, q);
	return 0;
}
