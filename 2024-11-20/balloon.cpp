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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 4e5 + 5;
const int INF = 1e9;
int T, n, root = 0;
vector <pii> qs[MAXN];

#define mid ((L + R) >> 1)

namespace seg {

	int mn[MAXN << 5], lazy[MAXN << 5];
	int ls[MAXN << 5], rs[MAXN << 5], nowr[MAXN << 5];
	int cnt = 0;

	inline void clean() {
		rep (i, 1, cnt) mn[i] = 0;
		rep (i, 1, cnt) lazy[i] = 0;
		rep (i, 1, cnt) ls[i] = 0;
		rep (i, 1, cnt) rs[i] = 0;
		rep (i, 1, cnt) nowr[i] = 0;
		cnt = 0;
	}

	inline void pushup(int cur) {
		mn[cur] = min(mn[ls[cur]], mn[rs[cur]]);
	}

	inline void pushdown(int cur, int L, int R) {
		if (!ls[cur]) ls[cur] = ++cnt, nowr[cnt] = nowr[cur], mn[cnt] = nowr[cnt] - mid;
		if (!rs[cur]) rs[cur] = ++cnt, nowr[cnt] = nowr[cur], mn[cnt] = nowr[cnt] - R;
		mn[ls[cur]] += lazy[cur];
		mn[rs[cur]] += lazy[cur];
		lazy[ls[cur]] += lazy[cur];
		lazy[rs[cur]] += lazy[cur];
		lazy[cur] = 0;
	}

	void add(int &cur, int L, int R, int l, int r, int val) {
		if (!cur) cur = ++cnt;
		if (l <= L && R <= r) {
			mn[cur] += val;
			lazy[cur] += val;
			return;
		}
		if (lazy[cur]) pushdown(cur, L, R);
		if (l <= mid) add(ls[cur], L, mid, l, r, val);
		if (r > mid) add(rs[cur], mid + 1, R, l, r, val);
		pushup(cur);
	}

	void make(int &cur, int L, int R, int l, int r, int val) {
		if (!cur) cur = ++cnt;
		if (l <= L && R <= r) {
			nowr[cur] = val;
			mn[cur] = val - R;
			return;
		}
		if (l <= mid) make(ls[cur], L, mid, l, r, val);
		if (r > mid) make(rs[cur], mid + 1, R, l, r, val);
		pushup(cur);
	}

} // namespace seg

int l[MAXN], r[MAXN], k[MAXN];

void solve() {
	seg::clean();
	root = 0;
	n = read();
	rep (i, 1, 2 * n) qs[i].clear();
	vector <int> h;
	rep (i, 1, n) {
		l[i] = read(), r[i] = read(), k[i] = read();
		h.emplace_back(l[i]);
		h.emplace_back(r[i]);
	}
	sort(h.begin(), h.end());
	h.erase(unique(h.begin(), h.end()), h.end());
	rep (i, 1, n) {
		l[i] = lower_bound(h.begin(), h.end(), l[i]) - h.begin() + 1;
		r[i] = lower_bound(h.begin(), h.end(), r[i]) - h.begin() + 1;
		qs[r[i]].emplace_back(l[i], k[i]);
	}
	int s = h.size();
	int lst = 0;
	rep (r, 1, s) {
		if (r > 1) seg::add(root, 1, INF, 1, lst, h[r - 1] - lst);
		seg::make(root, 1, INF, lst + 1, h[r - 1], h[r - 1] + 1);
		for (auto [l, k] : qs[r]) {
			seg::add(root, 1, INF, 1, h[l - 1], -k);
		}
		if (seg::mn[1] < 0) {
			// cerr << "de:" << h[r - 1] << " " << seg::mn[1] << endl;
			return puts("No"), void();
		}
		lst = h[r - 1];
	}
	puts("Yes");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("balloon.in", "r", stdin);
	freopen("balloon.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
