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

const int MAXN = 1e5 + 5, N = 1e5;
int n, m, k;

pair <int, int> e[MAXN << 1];

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)


namespace union_find {

	stack <pair <int, int> > s;
	int fa[MAXN << 1], siz[MAXN << 1];

	int find(int x) {return x == fa[x] ? x : find(fa[x]); }

	void merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) return;
		if (siz[fx] > siz[fy]) swap(fx, fy);
		s.push(dl(fx, siz[fx] == siz[fy]));
		fa[fx] = fy, siz[fy] += siz[fx] == siz[fy];
	}

	void _undo(const pair <int, int> x = s.top()) {
		siz[fa[x.ec]] -= x.fb;
		fa[x.ec] = x.ec;
		s.pop();
	}

	void undo(int x) { while ((int) s.size() > x) _undo(); }
} // namespace union_find

namespace seg {

	vector <int> v[MAXN << 2];

	void insert(int x, int L, int R, int l, int r, int id) {
		if (l <= L && R <= r) return v[x].push_back(id), void();
		if (l <= mid) insert(ls(x), L, mid, l, r, id);
		if (r > mid) insert(rs(x), mid + 1, R, l, r, id);
	}

	void solve(int x, int L, int R, int t = union_find::s.size()) {
		bool ok = 1;
		for (auto id : v[x]) {
			int u = e[id].ec, v = e[id].fb;
			int fu = union_find::find(u);
			int fv = union_find::find(v);
			/* cout << "debug:" << x << " " << L << " " << R << " " << id << endl; */
			/* cout << fu << " " << fv << endl; */
			if (fu == fv) {
				ok = 0;
				rep (i, L, R) puts("No");
				break;
			}
			union_find::merge(u + N, v);
			union_find::merge(v + N, u);
		}
		if (ok) {
			if (L == R) puts("Yes");
			else {
				solve(ls(x), L, mid);
				solve(rs(x), mid + 1, R);
			}
		}
		union_find::undo(t);
	}
} // namespace seg

signed main() {
	n = read(), m = read(), k = read();
	rep (i, 1, m) {
		int x = read(), y = read();
		int	l = read(), r = read();
		e[i] = dl(x, y);
		if (l == r) continue;
		seg::insert(1, 1, k, l + 1, r, i);
	}
	rep (i, 1, n) union_find::fa[i] = i;
	rep (i, 1, n) union_find::fa[i + N] = i + N;
	seg::solve(1, 1, k);
	return 0;
}
