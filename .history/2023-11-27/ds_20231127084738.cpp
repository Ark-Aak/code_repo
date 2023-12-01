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
		a[i] = min
	}
}

void modify(int l, int r, ll val) {
	int sid = id[l], eid = id[r];
	if (sid == eid) {
		for (int i = l; id[i] == sid; i++) {
			a[i] += val;
			a[i] = min(a[i], t[i]);
			a[i] = max(a[i], 0ll);
		}
		mn[sid] = 1e9; mx[sid] = 1e9;
		rep (i, ids[sid], ide[sid]) {
			mn[sid] = min(mn[sid], a[i]);
			mx[sid] = min(mx[sid], t[i] - a[i]);
		}
		return;
	}
	for (int i = l; id[i] == sid; i++) {
		a[i] += val;
		a[i] = min(a[i], t[i]);
		a[i] = max(a[i], 0ll);
	}
	mn[sid] = 1e9; mx[sid] = 1e9;
	rep (i, ids[sid], ide[sid]) {
		mn[sid] = min(mn[sid], a[i]);
		mx[sid] = min(mx[sid], t[i] - a[i]);
	}
	for (int i = r; id[i] == eid; i--) {
		a[i] += val;
		a[i] = min(a[i], t[i]);
		a[i] = max(a[i], 0ll);
	}
	mn[eid] = 1e9; mx[eid] = 1e9;
	rep (i, ids[eid], ide[eid]) {
		mn[eid] = min(mn[eid], a[i]);
		mx[eid] = min(mx[eid], t[i] - a[i]);
	}
	rep (i, sid + 1, eid - 1) {

	}
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
	rep (i, 1, n) id[i] = (i - 1) / len + 1;
	memset(ids, 0x7f, sizeof ids);
	rep (i, 1, n) ids[id[i]] = min(ids[id[i]], i);
	rep (i, 1, n) ide[id[i]] = max(ide[id[i]], i);
	rep (i, 1, m) {
		char op = getchar();
		while (op != '+' && op != '-') op = getchar();
		if (op ^ 45) {

		}
		else {

		}
	}
	return 0;
}
