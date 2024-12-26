#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
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

const int MAXN = 2e5 + 5;
int c, T;
int n, a[MAXN];

set <int> s;

namespace seg {

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

	int mx[MAXN << 2];

	void build(int x, int L, int R) {
		if (L == R) {
			mx[x] = a[L];
			return;
		}
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		mx[x] = max(mx[ls(x)], mx[rs(x)]);
	}

	int query(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) return mx[x];
		int res = 0;
		if (l <= mid) res = max(res, query(ls(x), L, mid, l, r));
		if (r > mid) res = max(res, query(rs(x), mid + 1, R, l, r));
		return res;
	}
} // namespace seg

int id[MAXN];
int lft[MAXN], rgt[MAXN];

void solve() {
	n = read();
	rep (i, 1, n) a[i] = read(), lft[i] = rgt[i] = 1;
	lft[1] = 0, rgt[n] = 0;
	seg::build(1, 1, n);
	rep (i, 1, n) id[i] = i;
	sort(id + 1, id + 1 + n, [](int a, int b) {
		return ::a[a] > ::a[b];
	});
	s.clear();
	s.insert(0), s.insert(n + 1);
	ll ans = 0;
	rep (i, 1, n) {
		int pos = id[i];
		if (lft[pos]) {
			int l = (*prev(s.lower_bound(pos - 1))) + 1;
			int r = (*s.upper_bound(pos)) - 1;
			int cl = seg::query(1, 1, n, l, pos - 1);
			int cr = seg::query(1, 1, n, pos, r);
			// cout << "cut1 " << pos - 1 << " <-> " << pos << endl;
			// cout << "cost " << cl << " " << cr << endl;
			ans += abs(cl - cr);
			lft[pos] = rgt[pos - 1] = 0;
		}
		if (rgt[pos]) {
			int l = (*prev(s.lower_bound(pos))) + 1;
			int r = (*s.upper_bound(pos + 1)) - 1;
			int cl = seg::query(1, 1, n, l, pos);
			int cr = seg::query(1, 1, n, pos + 1, r);
			// cout << "cut2 " << pos << " <-> " << pos + 1 << endl;
			// cout << "cost " << cl << " " << cr << endl;
			ans += abs(cl - cr);
			rgt[pos] = lft[pos + 1] = 0;
		}
		s.insert(pos);
	}
	print(ans), puts("");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
#endif
#endif
	c = read(), T = read();
	while (T --> 0) solve();
	return 0;
}
