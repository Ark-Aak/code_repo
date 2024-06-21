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

mt19937 _rnd(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) { return abs((int) _rnd()) % (r - l + 1) + l; }
int ord[10000005];

signed main() {
	freopen("data.in", "w", stdout);
	const int n = 10;
	printf("%d\n", n);
	rep (i, 1, n) ord[i] = i;
	const int root = rnd(1, n);
	shuffle(ord + 1, ord + n + 1, _rnd);
	rep (i, 1, n) {
		if (ord[i] == root) continue;
		if (rnd(0, 1)) printf("%d %d\n", root, ord[i]);
		else printf("%d %d\n", ord[i], root);
	}
	return 0;
}
