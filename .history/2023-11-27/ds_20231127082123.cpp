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

ll n, a[50005], b[50005], s[50005];
int id[50005];
int len;

void add(int l, int r, ll val) {
	int sid = id[l], eid = id[r];
	if (sid == eid) {
		rep (i, l, r) a[i] += val, s[sid] += val;
		return;
	}
	for (int i = l; id[i] == sid; i++) {
		a[i] += val, s[sid] += val;
	}
	for (int i = r; id[i] == eid; i--) {
		a[i] += val, s[eid] += val;
	}
	rep (i, sid + 1, eid - 1) {
		b[i] += val, s[i] += len * val;
	}
}

int query(int l, int r, int mod) {
	ll res = 0;
	int sid = id[l], eid = id[r];
	if (sid == eid) {
		rep (i, l, r) res = (res + a[i] + b[sid]) % mod;
		return res;
	}
	for (int i = l; id[i] == sid; i++) res = (res + a[i] + b[sid]) % mod;
	for (int i = r; id[i] == eid; i--) res = (res + a[i] + b[eid]) % mod;
	rep (i, sid + 1, eid - 1) res = (res + s[i]) % mod;
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("ds.in", "r", stdin);
	freopen("ds.out", "w", stdout);
#endif
#endif
	cin >> n;
	len = sqrt(n);
	rep (i, 1, n) cin >> a[i], id[i] = (i - 1) / len + 1, s[id[i]] += a[i];
	rep (i, 1, n) {
		int op, l, r, c;
		cin >> op >> l >> r >> c;
		if (op) {
			cout << query(l, r, c + 1) << '\n';
		}
		else add(l, r, c);
	}
	return 0;
}
