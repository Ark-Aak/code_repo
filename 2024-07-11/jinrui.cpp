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
#define int ll

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

int T, ans;
int n, ch[200];

void dfs(int step) {
	if (step > n) {
		int sum = 0;
		rep (i, 1, n) sum += ch[i] * i;
		if (sum == 0) return;
		ans += __gcd(n, sum) == 1;
		return;
	}
	ch[step] = 1;
	dfs(step + 1);
	ch[step] = 0;
	dfs(step + 1);
}

void solve() {
	ans = 0;
	n = read();
	dfs(1);
	print(ans), puts("");
}

signed main() {
#ifndef LOCAL
	ignore = freopen("jinrui.in", "r", stdin);
	ignore = freopen("jinrui.out", "w", stdout);
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
