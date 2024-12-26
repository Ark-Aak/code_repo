#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

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

uniform_int_distribution <int> d(-1000, 1001);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const bool getRand = 0;

inline int get() {
	if (getRand) return d(rnd);
	else return read();
}

const int MAXN = 5e5 + 5;
int n, m;
int a[MAXN];

struct frac {

	frac() { a = 0, b = 0; }
	frac(int a, int b) {
		this -> a = a;
		this -> b = b;
	}

	bool operator < (frac t) const {
		return a * t.b < b * t.a;
	}

	bool empty() { return a == 0 && b == 0; }

	int a, b;

};

frac ans[2005][2005];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("value.in", "r", stdin);
	freopen("value.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) a[i] = get();
if (!getRand) {
	m = read();
	if (n <= 2000) {
		rep (l, 1, n) {
			int res = 0;
			rep (r, l, n) {
				res += a[r];
				ans[l][r] = frac(res * res, r - l + 1);
				if (ans[l][r - 1].empty()) continue;
				if (ans[l][r] < ans[l][r - 1]) ans[l][r] = ans[l][r - 1];
			}
		}
		rep (i, 1, m) {
			int l = read(), r = read();
			frac res = frac();
			rep (i, l, r) {
				if (res.empty() || res < ans[i][r]) res = ans[i][r];
			}
			int _gcd = __gcd(res.a, res.b);
			res.a /= _gcd, res.b /= _gcd;
			print(res.a), putchar(32), print(res.b);
			puts("");
		}
	}
}
else {
	freopen("test.txt", "w", stdout);
	set <tuple <frac, int, int>, greater <tuple <frac, int, int> > > s;
	rep (i, 1, n) cout << a[i] << " ";
	cout << endl;
	rep (l, 1, n) {
		int res = 0;
		rep (r, l, n) {
			res += a[r];
			s.insert(dk(frac(res * res, r - l + 1), l, r));
		}
	}
	for (auto [f, l, r] : s) {
		cout << l << " " << r << " " << f.a << "/" << f.b << endl;
	}
}
	return 0;
}
