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

void modify(int l, int r, ll val) {
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("ds.in", "r", stdin);
	freopen("ds.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, n) read(t[i]);
	rep (i, 1, m) {
		char op = getchar();
		while (op != '+' && op != '-') op = getchar();
		int l, r, val;
		read(l), read(r), read(val);
		if (op ^ 45) modify(l, r, val);
		else modify(l, r, -val);
	}
	return 0;
}
