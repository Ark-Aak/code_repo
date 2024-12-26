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

const int MAXN = 1e5 + 5;
int T, n, m, a[10];
int sta[10];

int compress() {
	int res = 0;
	rep (i, 1, n) res = res * 10 + sta[i];
	return res;
}

unordered_map <int, bool> mp;

void dfs() {
	if (mp[compress()]) return;
	mp[compress()] = 1;
	rep (i, 1, n) {
		int nw = sta[i];
		if (i > 1) sta[i] = sta[i - 1], dfs();
		sta[i] = nw;
		if (i < n) sta[i] = sta[i + 1], dfs();
		sta[i] = nw;
	}
}

void solve() {
	//2m+1, m
	n = read(), m = read();
	mp.clear();
	rep (i, 1, n) a[i] = read(), sta[i] = a[i];
	if (n == m) {
		if (__builtin_popcount(n) == 1) putchar('1');
		else putchar('0');
		return;
	}
	dfs();
	print(mp.size() & 1);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
