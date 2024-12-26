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

mt19937 _rnd(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return _rnd() % (r - l + 1) + l; }

signed main() {
	freopen("data.in", "w", stdout);
	int n = 100, q = 100;
	cout << n << ' ' << q << endl;
	rep (i, 1, q) {
		int op = rnd(1, 2);
		int l1, l2, r1, r2;
		l1 = rnd(1, n), r1 = rnd(1, n);
		l2 = rnd(1, n), r2 = rnd(1, n);
		if (l1 > r1) swap(l1, r1);
		if (l2 > r2) swap(l2, r2);
		cout << op << ' ' << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;
	}
	return 0;
}
