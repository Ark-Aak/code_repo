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

const int MAXN = 1e5 + 5;
int n;
multiset <int> pre, suf;
struct node {
	int x, y;
} p[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("boast.in", "r", stdin);
	freopen("boast.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) p[i].x = read(), p[i].y = read();
	sort(p + 1, p + 1 + n, [](node a, node b) {
		return a.y < b.y;
	});
	pre.insert(p[1].x);
	rep (i, 2, n) suf.insert(p[i].x + p[i].y);
	int ans = 1e18;
	rep (i, 2, n - 1) {
		int myval = p[i].x + p[i].y;
		suf.erase(suf.find(myval));
		ans = min(ans, (*pre.begin()) + myval + (*suf.begin()));
		pre.insert(p[i].x);
	}
	print(ans), puts("");
	return 0;
}