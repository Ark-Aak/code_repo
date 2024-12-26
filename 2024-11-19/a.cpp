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
const double PI = acos(-1.0);
const double eps = 1e-6;
int n, m;
int ansp, ansq;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res =  res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	const int mk = floor(2.0 * m / PI + eps);
	// cerr << "mk:" << mk << endl;
	// mk 段以上的圆弧直接去原点
	int sumql = 0;
	rep (i, 1, n) {
		// 1~i-1 和 1~n-i 的等差数列
		sumql = (sumql + (i * (i - 1) / 2) % MOD) % MOD;
		sumql = (sumql + ((n - i + 1) * (n - i) / 2) % MOD) % MOD;
	}
	const int invM = qpow(2 * m, MOD - 2);
	int sumpl = 0;
	rep (i, 1, n) {
		// 2/2m, 4/2m, 6/2m
		sumpl = (sumpl + (i * (i + 1) % MOD) * invM % MOD) % MOD;
		sumpl = (sumpl + 2 * i * invM % MOD * (n - i) % MOD) % MOD;
	}
	const int cnt = 2 * m;
	rep (i, 1, cnt) {
		const int my = ((n + 1) * n / 2) % MOD;
		ansq = (ansq + (cnt - 2 * mk - 1) * my % MOD * n % MOD * 2 % MOD) % MOD;
		ansq = (ansq + sumql * (2 * mk + 1) % MOD) % MOD;
		ansp = (ansp + sumpl * (mk * (mk + 1) % MOD) % MOD) % MOD;
	}
	ansp = ansp * qpow(2, MOD - 2) % MOD;
	ansq = ansq * qpow(2, MOD - 2) % MOD;
	ansq = (ansq + (n * (n + 1) / 2) % MOD * 2 % MOD * m % MOD) % MOD;
	print(ansp), putchar(32), print(ansq), puts("");
	// cout << ansq << endl;
	return 0;
}
