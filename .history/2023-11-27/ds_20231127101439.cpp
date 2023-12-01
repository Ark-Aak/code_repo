#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 2e5 + 5, SQRT = 450;
ll n, m, a[MAXN], t[MAXN];
int mdf[SQRT];
int id[MAXN];
ll mn[MAXN], mx[MAXN];
int len, ids[MAXN], ide[MAXN];

void assign(int l, int r, int val) {
	if (::id[l] != ::id[r]) return;
	int id = ::id[l];
	rep (i, l, r) {
		a[i] += val;
		a[i] = min(a[i], t[i]);
		a[i] = max(a[i], 0ll);
	}
	mn[id] = mx[id] = 1e9;
	rep (i, ids[id], ide[id]) {
		mn[id] = min(mn[id], a[i]);
		mx[id] = min(mx[id], t[i] - a[i]);
	}
}

void pushdown(int blk) {
	assign(ids[blk], ide[blk], mdf[blk]);
	mdf[blk] = 0;
}

void modify(int l, int r, ll val) {
	int sid = id[l], eid = id[r];
	if (sid == eid) {
		pushdown(sid);
		assign(l, r, val);
		return;
	}
	pushdown(sid);
	assign(l, ide[sid], val);
	pushdown(eid);
	assign(ids[eid], r, val);
	rep (i, sid + 1, eid - 1) {
		int nw = mdf[i] + val;
		if (nw > 0) {
			if (nw <= mx[i]) mdf[i] += val;
			else pushdown(i), assign(ids[i], ide[i], val);
		}
		else {
			if (abs(nw) <= mn[i]) mdf[i] += val;
			else pushdown(i), assign(ids[i], ide[i], val);
		}
	}
}

struct query {
	int type, l, r, val;

	query() {}

	query(int _type, int _l, int _r, int _val) {
		type = _type, l = _l, r = _r, val = _val;
	}
} q[MAXN];

bool flg = 1;

namespace subtask1 {
	int cf[MAXN];
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("ds.in", "r", stdin);
	freopen("ds.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	len = sqrt(n);
	rep (i, 1, n) read(t[i]);
	int mxid = 0;
	rep (i, 1, n) id[i] = (i - 1) / len + 1, mxid = max(mxid, id[i]);
	memset(ids, 0x7f, sizeof ids);
	rep (i, 1, n) ids[id[i]] = min(ids[id[i]], (ll) i);
	rep (i, 1, n) ide[id[i]] = max(ide[id[i]], (ll) i);
	rep (i, 1, m) {
		char op = getchar();
		while (op != '+' && op != '-') op = getchar();
		int l, r, val;
		read(l), read(r), read(val);
		if (op != '+') flg = 0;
		q[i] = query(op == '+' ? 1 : -1, l, r, val);
	}
	if (flg) {
		rep (i, 1, m) {
			subtask1::cf[q[i].l] += q[i].val;
			subtask1::cf[q[i].r + 1] -= q[i].val;
		}
		int ans = 0;
		rep (i, 1, n) {
			ans += subtask1::cf[i];
			print(min(ans, t[i])), putchar(32);
		}
		return 0;
	}
	rep (i, 1, m) {
		modify(q[i].l, q[i].r, q[i].val * q[i].type);
	}
	rep (i, 1, mxid) pushdown(i);
	rep (i, 1, n) print(a[i]), putchar(32);
	return 0;
}
