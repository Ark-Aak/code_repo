/*
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immaxtrin.h>
#include <emmaxtrin.h>
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

const int MAXN = 5e5 + 5;
int n, q, k, d;

namespace seg {

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

	int sufMax[MAXN << 2], preMax[MAXN << 2], sum[MAXN << 2], maxSum[MAXN << 2];
	int maxL[MAXN << 2], maxR[MAXN << 2];
	int preL[MAXN << 2], sufR[MAXN << 2];

	void pushup(int x) {
		sum[x] = sum[ls(x)] + sum[rs(x)];
		preMax[x] = max(preMax[ls(x)], sum[ls(x)] + preMax[rs(x)]);
		sufMax[x] = max(sufMax[rs(x)], sum[rs(x)] + sufMax[ls(x)]);
		maxSum[x] = max(max(maxSum[ls(x)], maxSum[rs(x)]), sufMax[ls(x)] + preMax[rs(x)]);
	}

	void build(int x, int L, int R) {
		if (L == R) {
			sum[x] = preMax[x] = sufMax[x] = maxSum[x] = -k;
			maxL[x] = maxR[x] = preL[x] = sufR[x] = L;
			return;
		}
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		pushup(x);
	}

	void modify(int x, int L, int R, int p, int val) {
		if (L == R) {
			sum[x] += val;
			preMax[x] += val;
			sufMax[x] += val;
			maxSum[x] += val;
			return;
		}
		if (p <= mid) modify(ls(x), L, mid, p, val);
		else modify(rs(x), mid + 1, R, p, val);
		pushup(x);
	}

	int querySum(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) return sum[x];
		int res = 0;
		if (l <= mid) res += querySum(ls(x), L, mid, l, r);
		if (r > mid) res += querySum(rs(x), mid + 1, R, l, r);
		return res;
	}

} // namespace seg

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("glass.in", "r", stdin);
	freopen("glass.out", "w", stdout);
#endif
#endif
	n = read(), q = read(), k = read(), d = read();
	seg::build(1, 1, n);
	while (q --> 0) {
		int x = read(), y = read();
		seg::modify(1, 1, n, x, y);
		// auto res = seg::queryMaxSum(1, 1, n, 1, n);
		int sum = seg::maxSum[1];
		// cerr << "l,r:" << l << ' ' << r << endl;
		// cerr << seg::querySum(1, 1, n, l, r) << endl;
		// assert(seg::querySum(1, 1, n, l, r) == sum);
		sum -= d * k;
		// cerr << sum << endl;
		if (sum <= 0) puts("Yes");
		else puts("No");
	}
	return 0;
}
*/
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

int n, q, k, d;

int res[1005];

signed main() {
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	// cnm sb T3 出题人
	n = read(), q = read(), k = read(), d = read();
	while (q --> 0) {
		int x = read(), y = read();
		res[x] += y;
		bool flg = 0;
		rep (l, 1, n) {
			int sum = 0;
			rep (r, l, n) {
				sum += res[r];
				int R = min(n, r + d);
				int res = sum - (R - l + 1) * k;
				if (res > 0) {
					flg = 1;
					puts("No");
					break;
				}
			}
			if (flg) break;
		}
		if (!flg) puts("Yes");
	}
	return 0;
}
