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

const int MAXN = 10;
const int MOD = 998244353;
int n, a[MAXN], ch[MAXN], na[MAXN], tot;

void dfs(int step) {
	if (step > n) {
		rep (i, 1, n) {
			na[i] = a[i];
		}
		rep (i, 1, n) {
			na[i] -= ch[i];
			na[i % n + 1] += ch[i];
		}
		int ans = 1;
		rep (i, 1, n) ans = 1ll * ans * na[i] % MOD;
		tot = (tot + ans) % MOD;
		return;
	}
	rep (i, 0, a[step]) ch[step] = i, dfs(step + 1);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("iv.in", "r", stdin);
	freopen("iv.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) a[i] = read();
	dfs(1);
	print(tot), puts("");
	return 0;
}
