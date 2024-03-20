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

int n, m, flg, ans;
int a[MAXN], b[MAXN], c[MAXN];
int suma[MAXN], sumb[MAXN];
int tl, tr, pl, pr;

inline void upd(int val, tuple <int, int, int, int> p) {
	if (flg) swap(get<0>(p), get<2>(p)), swap(get<1>(p), get<3>(p));
	if (val > ans) ans = val, tie(tl, tr, pl, pr) = p;
}

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

namespace seg {

	int mx[MAXN << 2], lazy[MAXN << 2];

	void pushup(int x) { mx[x] = max(mx[ls(x)], mx[rs(x)]); }

	void pushdown(int x, int L, int R) {
		if (L == R) return;
		mx[ls(x)] += lazy[x], mx[rs(x)] += lazy[x];
		lazy[ls(x)] += lazy[x], lazy[rs(x)] += lazy[x];
		lazy[x] = 0;
	}

	void build(int x, int L, int R) {
		lazy[x] = 0, mx[x] = 0;
		if (L == R) return mx[x] = suma[n] - sumb[L - 1], void();
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		pushup(x);
	}

	void modify(int x, int L, int R, int l, int r, int val) {
		if (l <= L && R <= r) return mx[x] += val, lazy[x] += val, void();
		if (lazy[x]) pushdown(x, L, R);
		if (l <= mid) modify(ls(x), L, mid, l, r, val);
		if (r >  mid) modify(rs(x), mid + 1, R, l, r, val);
		pushup(x);
	}

	int query(int x, int L, int R) {
		if (L == R) return L;
		if (lazy[x]) pushdown(x, L, R);
		int val = 0;
		if (mx[x] == mx[ls(x)]) val = query(ls(x), L, mid);
		else val = query(rs(x), mid + 1, R);
		pushup(x);
		return val;
	}
} // namespace seg

int sl[MAXN], sr[MAXN];
int tpl, tpr;

void solve() {
	int p = lower_bound(suma + 1, suma + 1 + n, ((suma[n] + 1) >> 1)) - suma;
	seg::build(1, 1, m);
	tpl = tpr = 0;
	rep (i, 1, m) {
		if (b[i]) {
			if (b[i] <= p) {
				while (tpl && b[i] > b[sl[tpl]]) {
					seg::modify(1, 1, m, sl[tpl - 1] + 1, sl[tpl], suma[b[sl[tpl]]]);
					--tpl;
				}
				seg::modify(1, 1, m, sl[tpl] + 1, i, -suma[b[i]]);
				sl[++tpl] = i;
			}
			else {
				while (tpr && b[i] < b[sr[tpr]]) {
					seg::modify(1, 1, m, sr[tpr - 1] + 1, sr[tpr], suma[n] - suma[b[sr[tpr]] - 1]);
					--tpr;
				}
				seg::modify(1, 1, m, sr[tpr] + 1, i, -suma[n] + suma[b[i] - 1]);
				sr[++tpr] = i;
			}
		}
		int j = seg::query(1, 1, m);
		int pl = lower_bound(sl + 1, sl + 1 + tpl, j) - sl;
		int pr = lower_bound(sr + 1, sr + 1 + tpr, j) - sr;
		pl = pl <= tpl ? b[sl[pl]] + 1 : 1;
		pr = pr <= tpr ? b[sr[pr]] - 1 : n;
		upd(sumb[i] + seg::mx[1], dk(pl, pr, j, i));
	}
}

signed main() {
	n = read(), m = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) suma[i] = suma[i - 1] + read();
	rep (i, 1, m) c[read()] = i;
	rep (i, 1, m) sumb[i] = sumb[i - 1] + read();
	rep (i, 1, n) a[i] = c[a[i]], b[a[i]] = i;
	upd(suma[n], dk(1, n, 0, 0));
	upd(sumb[m], dk(0, 0, 1, m));
	solve();
	swap(n, m), swap(a, b), swap(suma, sumb), flg = 1;
	solve();
	print(ans), putchar(10);
	if (tl > tr) tl = tr = 0;
	print(tl), putchar(32), print(tr), putchar(10);
	if (pl > pr) pl = pr = 0;
	print(pl), putchar(32), print(pr), putchar(10);
}
