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

const int MAXN = 5e5 + 5;
int cnt[MAXN];

mt19937 _rnd(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return _rnd() % (r - l + 1) + l; }

int n, q, k, d;

signed main() {
	freopen("data.in", "w", stdout);
	n = rnd(1, 10), q = rnd(1, 10), k = rnd(1, 10), d = rnd(1, n - 1);
	cout << n << ' ' << q << ' ' << k << ' ' << d << endl;
	rep(i, 1, q) {
		int x = rnd(1, n), y = rnd(-5, 5);
		while (cnt[x] + y < 0) y = rnd(-5, 5);
		cnt[x] += y;
		cout << x << ' ' << y << endl;
	}
	return 0;
}
