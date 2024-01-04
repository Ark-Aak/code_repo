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

//#define int ll

const int MAXN = 5e5 + 5;
int sid, n, m;
int x[MAXN], y[MAXN], w[MAXN];
int r[MAXN], c[MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

vector <tuple <int, int, int, int, int> > v;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("walpurgis.in", "r", stdin);
	freopen("walpurgis.out", "w", stdout);
#endif
#endif
	read(sid);
	read(n), read(m);
	rep (i, 1, n) read(x[i]), read(y[i]), read(w[i]);
	rep (i, 1, m) read(r[i]), read(c[i]);
	//if (sid <= 2) {
		rep (i, 1, n) {
			int a = qpow(2, (int) log2(x[i]));
			int b = qpow(2, (int) log2(y[i]));
			v.emplace_back(make_tuple(x[i], y[i], a, b, w[i]));
		}
		rep (i, 1, m) {
			ll ans = 0;
			for (auto t : v) {
				int R = r[i], C = c[i];
				int x, y, a, b, w;
				tie(x, y, a, b, w) = t;
				if (R < x) continue;
				if (C < y) continue;
				R -= x, C -= y;
				if (R % a == 0 && C % b == 0) {
					ans += w;
				}
			}
			print(ans), putchar(10);
		}
	//}
	//cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	return 0;
}
