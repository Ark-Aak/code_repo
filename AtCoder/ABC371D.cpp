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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 2e5 + 5;
int n;
int q, b[MAXN], pre[MAXN];
pii x[MAXN];

signed main() {
	n = read();
	rep (i, 1, n) x[i].ec = read();
	rep (i, 1, n) x[i].fb = read();
	q = read();
	sort(x + 1, x + 1 + n);
	rep (i, 1, n) pre[i] = pre[i - 1] + x[i].fb, b[i] = x[i].ec;
	while (q --> 0) {
		int l = read(), r = read();
		int L = lower_bound(b + 1, b + 1 + n, l) - b - 1;
		int R = upper_bound(b + 1, b + 1 + n, r) - b - 1;
		print(pre[R] - pre[L]), puts("");
	}
	return 0;
}
