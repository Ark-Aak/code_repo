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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MOD = 998244353;
int n, res, m, ans;

int ch[100];

void dfs(int step) {
	if (step > n) {
		int t = 1;
		rep (i, 1, n) t *= ch[i], t %= m;
		if (t == res) ans++;
		ans %= MOD;
		return;
	}
	rep (i, 0, m - 1) ch[step] = i, dfs(step + 1);
}

int qpow(int a, int b) {
	a %= MOD;
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("equiv.in", "r", stdin);
	freopen("equiv.out", "w", stdout);
#endif
#endif
	n = read(), res = read(), m = read();
	if (n <= 5 && m <= 10) {
		dfs(1);
		print(ans), puts("");
		return 0;
	}
	else {
		if (res == 0) {
			int posN = (n + 1) / 2;
			int sumP = (qpow(m * m % MOD, posN + 1) - m * m % MOD + MOD) % MOD * qpow(m * m - 1, MOD - 2) % MOD;
			if (n & 1) sumP = sumP * qpow(m, MOD - 2) % MOD;
			int negN = n / 2;
			int sumN = (qpow(m * m % MOD, negN + 1) - m * m % MOD + MOD) % MOD * qpow(m * m - 1, MOD - 2) % MOD;
			if ((n & 1) == 0) sumN = sumN * qpow(m, MOD - 2) % MOD;
			print((sumP - sumN + MOD) % MOD);
			puts("");
		}
	}
	return 0;
}
