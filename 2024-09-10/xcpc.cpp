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

const int MAXN = 3e5 + 5;
int n, q, a[MAXN], k[MAXN];
bool flg1 = 1, flg2 = 1, flg3 = 1;
int ch[MAXN], sum[MAXN];
int ff[MAXN];

void dfs(int step, int lst) {
	if (step > n) {
		rep (i, 1, n) sum[i] = 0;
		rep (i, 1, n) sum[ch[i]]++;
		int f = 0;
		rep (i, 1, n) f += sum[ch[i]] >= a[i];
		ff[lst] = max(ff[lst], f);
		return;
	}
	rep (i, 1, lst + 1) ch[step] = i, dfs(step + 1, max(lst, i));
}

int psum[MAXN], pre[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("xcpc.in", "r", stdin);
	freopen("xcpc.out", "w", stdout);
#endif
#endif
	n = read(), q = read();
	rep (i, 1, n) {
		a[i] = read();
		if (a[i] < n - 1) flg2 = 0;
	}
	rep (i, 1, q) {
		k[i] = read();
		if (k[i] != 1 && k[i] != n) flg1 = 0;
		if (k[i] > 2 && k[i] < n - 1) flg3 = 0;
	}
	if (flg1) {
		int sum = 0;
		rep (i, 1, n) sum += a[i] == 1;
		rep (i, 1, q) {
			if (k[i] == 1) print(n), putchar(32);
			else print(sum), putchar(32);
		}
		return 0;
	}
	if (flg2) {
		int sum1 = 0, sum2 = 0;
		rep (i, 1, n) sum1 += a[i] == n - 1, sum2 += a[i] == n;
		rep (i, 1, q) {
			if (k[i] > 2) print(0), putchar(32);
			else if (k[i] == 2) print(sum1), putchar(32);
			else print(n), putchar(32);
		}
		return 0;
	}
	if (flg3) {
		int sum1 = 0, sum2 = 0;
		rep (i, 1, n) sum1 += a[i] == 1;
		rep (i, 1, n) sum2 += a[i] == 2;
		rep (i, 1, n) psum[a[i]]++;
		rep (i, 1, n) pre[i] += pre[i - 1] + psum[i];
		rep (i, 1, q) {
			if (k[i] == 1) print(n), putchar(32);
			else if (k[i] == n) print(sum1), putchar(32);
			else if (k[i] == n - 1) {
				print(sum1 + min(sum2, 2)), putchar(32);
			}
			else {
				print(pre[n - 1]), putchar(32);
			}
		}
		return 0;
	}
	rep (i, 1, n) ff[i] = -1;
	dfs(1, 0);
	rep (i, 1, q) {
		print(ff[k[i]]), putchar(32);
	}
	return 0;
}
