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

int n, a[1 << 21];
int mx1[1 << 21], mx2[1 << 21];

void merge(int a, int b) {
	if (mx1[a] > mx1[b]) {
		mx2[a] = max(mx2[a], mx1[b]);
	}
	else {
		int tp = mx1[a];
		mx1[a] = mx1[b];
		mx2[a] = max(tp, mx2[b]);
	}
}

signed main() {
	n = read();
	const int l = 1 << n;
	rep (i, 0, l - 1) a[i] = mx1[i] = read();
	rep (i, 0, n - 1) {
		rep (j, 0, l - 1) if (j >> i & 1) merge(j, j ^ (1 << i));
	}
	int ans = 0;
	rep (j, 1, l - 1) print(ans = max(ans, mx1[j] + mx2[j])), puts("");
	return 0;
}
