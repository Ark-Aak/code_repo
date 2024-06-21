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

const int MOD = 1e9 + 7;
int n1, n2, n3, n4;
int ans = 0;

void dfs(int step, int s1, int s2, int s3, int s4, int lst) {
	if (s1 < 0 || s2 < 0 || s3 < 0 || s4 < 0) return;
	if (step > n1 + n2 + n3 + n4) {
		ans++;
		ans %= MOD;
		return;
	}
	if (lst == 1) {
		dfs(step + 1, s1, s2 - 1, s3, s4, 2);
		dfs(step + 1, s1, s2, s3 - 1, s4, 3);
		dfs(step + 1, s1, s2, s3, s4 - 1, 4);
	}
	else if (lst == 2) {
		dfs(step + 1, s1 - 1, s2, s3, s4, 1);
		dfs(step + 1, s1, s2, s3 - 1, s4, 3);
		dfs(step + 1, s1, s2, s3, s4 - 1, 4);
	}
	else if (lst == 3) {
		dfs(step + 1, s1 - 1, s2, s3, s4, 1);
		dfs(step + 1, s1, s2 - 1, s3, s4, 2);
		dfs(step + 1, s1, s2, s3, s4 - 1, 4);
	}
	else if (lst == 4) {
		dfs(step + 1, s1 - 1, s2, s3, s4, 1);
		dfs(step + 1, s1, s2 - 1, s3, s4, 2);
		dfs(step + 1, s1, s2, s3 - 1, s4, 3);
	}
	else {
		dfs(step + 1, s1 - 1, s2, s3, s4, 1);
		dfs(step + 1, s1, s2 - 1, s3, s4, 2);
		dfs(step + 1, s1, s2, s3 - 1, s4, 3);
		dfs(step + 1, s1, s2, s3, s4 - 1, 4);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
#endif
#endif
	n1 = read(), n2 = read(), n3 = read(), n4 = read();
	dfs(1, n1, n2, n3, n4, 0);
	print(ans), puts("");
	return 0;
}
