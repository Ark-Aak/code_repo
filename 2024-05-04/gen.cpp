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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r) { return abs((int) rnd()) % (r - l + 1) + l; }

signed main() {
	freopen("data.in", "w", stdout);
	const int n = 5, m = 1, q = 15, p = 1e9 + 7;
	cout << n << " " << m << " " << q << " " << p << endl;
	rep (i, 1, m) {
		int lst0 = 1, lst1 = 1, tp;
		rep (j, 1, n) {
			if (j <= 2) cout << Rand(1, 50) << " ";
			else cout << (tp = lst0 + lst1) << " ", lst1 = lst0, lst0 = tp;
		}
		cout << endl;
	}
	rep (i, 1, q) {
		int op = Rand(1, 2);
		cout << op << " ";
		int l = Rand(1, n);
		int r = min(l + 5, n);
		if (l > r) swap(l, r);
		if (op == 1) cout << Rand(1, m) << " " << l << " " << r << endl;
		if (op == 2) cout << Rand(1, m) << " " << l << " " << r << " " << Rand(2, 2) << endl;
		if (op == 3) cout << Rand(1, m) << " " << l << " " << r << " " << Rand(1, 1e9) << endl;
		if (op == 4) cout << Rand(1, m) << " " << Rand(1, m) << " " << l << " " << r << endl;
	}
	return 0;
}
