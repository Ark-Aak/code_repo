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

const int MAXN = 1e5 + 5;
int n, m;

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

bool stmer;

namespace seg {

	int mn[MAXN << 2][31];
	int lk[MAXN << 2][31];
	int val[MAXN << 2][31];
	int lazy[MAXN << 2][31];
	bool active[MAXN << 2];

	void build(int x, int L, int R) {
		active[x] = 1;
		if (L == R) return;
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
	}

	void pushdown(int x, int L, int R) {
		rep (i, 1, 30) {
			if (!lazy[x][i]) continue;
			mn[ls(x)][i] += lazy[x][i];
			mn[rs(x)][i] += lazy[x][i];
			if (R - L == 1) {
				if (active[ls(x)]) val[ls(x)][i] += lazy[x][i];
				if (active[rs(x)]) val[rs(x)][i] += lazy[x][i];
			}
			else {
				lazy[ls(x)][i] += lazy[x][i];
				lazy[rs(x)][i] += lazy[x][i];
			}
			lazy[x][i] = 0;
		}
	}

	void pushup(int x) {
		rep (i, 1, 30) {
			mn[x][i] = min(mn[ls(x)][i], mn[rs(x)][i]);
			lk[x][i] = min(active[ls(x)] ? (int) 1e9 : lk[ls(x)][i], active[rs(x)] ? (int) 1e9 : lk[rs(x)][i]);
		}
		active[x] = active[ls(x)] && active[rs(x)];
	}

	void change(int x, int L, int R, int pos) {
		if (L == R) {
			active[x] = !active[x];
			if (active[x]) {
				rep (i, 1, 30) mn[x][i] = val[x][i];
				rep (i, 1, 30) lk[x][i] = 1e9;
			}
			else {
				rep (i, 1, 30) mn[x][i] = 1e9;
				rep (i, 1, 30) lk[x][i] = val[x][i];
			}
			return;
		}
		pushdown(x, L, R);
		if (pos <= mid) change(ls(x), L, mid, pos);
		else change(rs(x), mid + 1, R, pos);
		pushup(x);
	}

	void add(int x, int L, int R, int l, int r, int val, int cnt) {
		if (l <= L && R <= r) {
			if (L == R && !active[x]) return;
			mn[x][val] += cnt;
			if (L != R) lazy[x][val] += cnt;
			else seg::val[x][val] += cnt;
			return;
		}
		pushdown(x, L, R);
		if (l <= mid) add(ls(x), L, mid, l, r, val, cnt);
		if (r > mid) add(rs(x), mid + 1, R, l, r, val, cnt);
		pushup(x);
	}

	bool query(int x, int L, int R, int l, int r, int p, int a) {
		if (l <= L && R <= r) return mn[x][p] >= a && ((!active[x]) ? lk[x][p] >= a : true);
		pushdown(x, L, R);
		bool res = 1;
		if (l <= mid) res &= query(ls(x), L, mid, l, r, p, a);
		if (r > mid) res &= query(rs(x), mid + 1, R, l, r, p, a);
		pushup(x);
		return res;
	}
} // namespace seg

bool edmer;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tempIate.in", "r", stdin);
	freopen("tempIate.out", "w", stdout);
#endif
#endif
	cerr << (&stmer - &edmer) / 1024.0 / 1024.0 << "MiB" << endl;
	n = read(), m = read();
	seg::build(1, 1, n);
	rep (i, 1, m) {
		int op = read();
		if (op == 1) {
			int pos = read();
			seg::change(1, 1, n, pos);
		}
		else if (op == 2) {
			int l = read(), r = read(), x = read();
			int c = 2;
			vector <pii> factors;
			while (x > 1) {
				int cnt = 0;
				while (x % c == 0) cnt++, x /= c;
				if (cnt) factors.push_back(dl(c, cnt));
				++c;
			}
			for (auto [p, a] : factors) {
				seg::add(1, 1, n, l, r, p, a);
			}
		}
		else {
			int l = read(), r = read(), x = read();
			int c = 2;
			vector <pii> factors;
			while (x > 1) {
				int cnt = 0;
				while (x % c == 0) cnt++, x /= c;
				if (cnt) factors.push_back(dl(c, cnt));
				++c;
			}
			bool res = 1;
			for (auto [p, a] : factors) {
				res &= seg::query(1, 1, n, l, r, p, a);
			}
			if (!res) {
				puts("NO");
				continue;
			}
			puts("YES");
			for (auto [p, a] : factors) {
				seg::add(1, 1, n, l, r, p, -a);
			}
		}
	}
	return 0;
}
