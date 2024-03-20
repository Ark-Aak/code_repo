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

const int MAXN = 1e5 + 5;
ll n, m, cnt;
ll c[MAXN], b[MAXN], a[MAXN];
bool flg1 = 1, flg2 = 1;

struct node {
	int a, b;
} item[MAXN << 1];

const double EPS = 1e-8;

bool eq(double a, double b) {
	return fabs(a - b) <= EPS;
}

ll ans = 0;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, n) {
		read(c[i]);
		item[++cnt].a = c[i];
		item[cnt].b = 0;
	}
	rep (i, 1, m) {
		read(a[i]), read(b[i]);
		if (a[i] != 0) flg1 = 0;
		if (b[i] != 0) flg2 = 0;
		item[++cnt].a = a[i];
		item[cnt].b = b[i];
	}
	sort(item + 1, item + 1 + cnt, [](node a, node b) {
		double mxa = max(a.a * 1.0, a.b * 1.0 / 2.0);
		double mxb = max(b.a * 1.0, b.b * 1.0 / 2.0);
		return mxa > mxb;
	});
	int v;
	read(v);
	rep (i, 1, cnt) {
		node a = item[i];
		double ka = a.a * 1.0, kb = a.b * 1.0 / 2.0;
		if (!v) break;
		if (eq(ka, kb) && v >= 1) --v, ans += a.a;
		else if (ka > kb && v >= 1) --v, ans += a.a;
		else if (ka < kb && v >= 2) v -= 2, ans += a.b;
		else if (ka < kb && v >= 1) --v, ans += a.a;
	}
	cout << ans;
	return 0;
}
