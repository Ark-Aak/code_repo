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

const int MAXN = 120005;
int n, m, a[MAXN];
double b[MAXN], sum[MAXN];

void solve() {
	int sum_positive = 0;
	int sum_negative = 0;
	rep (j, 1, n) {
		if (a[j] >= 0) sum_positive += a[j];
		else sum_negative += -a[j];
	}
	rep (j, 1, n) {
		if (a[j] >= 0) b[j] = 1.0 * a[j] / (1.0 * sum_positive);
		else b[j] = 1.0 * a[j] / (1.0 * sum_negative);
	}
	rep (j, 1, n) sum[j] = sum[j - 1] + b[j];
	double maxn = -1e9;
	int pos = 0;
	rep (j, 1, n) {
		if (sum[j] > maxn) maxn = sum[j], pos = j;
	}
	print(pos), puts("");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, n) a[i] = read();
	if (n <= 3000) {
		solve();
		rep (i, 1, m) {
			int p = read(), v = read();
			a[p] = v;
			solve();
		}
	}
	else {
		int pos = 0;
		rep (i, 1, n - 1) if (a[i] >= 0 && a[i + 1] < 0) { pos = i; break; }
		print(pos), puts("");
		rep (i, 1, m) {
			int p = read(), v = read();
			if (a[p] < 0 && v > 0) pos++;
			if (a[p] > 0 && v < 0) pos--;
			a[p] = v;
			print(pos), puts("");
		}
	}
	return 0;
}