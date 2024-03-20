#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <immintrin.h>
#include <emmintrin.h>

#include <iostream>
#include <algorithm>
#include <cmath>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

char buf[1 << 20], *p1, *p2;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)

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

const int MAXN = 2e5 + 5;
int n, V, L;
int *f, *ans;
int a[MAXN], b[MAXN], c[MAXN];

__m256i ans_bk[(MAXN >> 3) + 1], f_bk[(MAXN >> 3) + 1];
/* int f[MAXN], ans[MAXN]; */

inline void update(int* v, int l, int r, int val) {
	/* rep (i, l, r) v[i] = val; */
	int i = l;
	for (; i <= r && i & 7; i++) v[i] = val;
	for (; i + 7 <= r; i += 8) {
		__m256i* p = (__m256i*) (v + i);
		*p = _mm256_set1_epi32(val);
	}
	for (; i <= r; i++) v[i] = val;
}

inline void copy(int* frm, int* dst, int l, int r) {
	/* rep (i, l, r) dst[i] = frm[i]; */
	int i = l;
	for (; i <= r && i & 7; i++) dst[i] = frm[i];
	for (; i + 7 <= r; i += 8) {
		__m256i* p = (__m256i*) (frm + i);
		__m256i* q = (__m256i*) (dst + i);
		*q = *p;
	}
	for (; i <= r; i++) dst[i] = frm[i];
}

inline void work(int* v, int c, int w) {
	_rep (i, V, c) v[i] = max(v[i], v[i - c] + w);
}

inline ll sum(int* v, int l, int r) {
	ll res = 0;
	/* rep (i, l, r) res += v[i]; */
	for (; l <= r && l & 7; l++) res += v[l];
	for (; l + 7 <= r; l += 8) {
		__m256i* p = (__m256i*) (v + l);
		__m256i pack = _mm256_loadu_si256(p);
		res += _mm256_extract_epi32(pack, 0);
		res += _mm256_extract_epi32(pack, 1);
		res += _mm256_extract_epi32(pack, 2);
		res += _mm256_extract_epi32(pack, 3);
		res += _mm256_extract_epi32(pack, 4);
		res += _mm256_extract_epi32(pack, 5);
		res += _mm256_extract_epi32(pack, 6);
		res += _mm256_extract_epi32(pack, 7);
	}
	for (; l <= r; l++) res += v[l];
	return res;
}

void solve(int L, int R, int qL, int qR) {
	if (qL > qR) return;
	if (L == R) {
		update(ans, qL, qR, L);
		return;
	}
	__m256i* p = new __m256i[(MAXN + 8) >> 3], *q = new __m256i[(MAXN + 8) >> 3];
	int *g = (int*) p, *h = (int*) q;
	/* int g[MAXN], h[MAXN]; */
	copy(f, h, 0, V);
	int x = (qL + qR) >> 1;
	rep (i, qL, x - 1) work(h, a[i], c[i]);
	rep (i, x, L - 1) work(h, b[i], c[i]);
	int nowL = max(L, x) - 1, nowR = R + 1;
	int pL = max(L, x), pR = R;
	while (pL < pR) {
		int mid = (pL + pR) >> 1;
		copy(h, g, 0, V);
		rep (i, pL, mid) work(g, b[i], c[i]);
		rep (i, mid + 1, pR) work(g, a[i], c[i]);
		ll Sum = sum(g, 1, V);
		if (Sum <= 1ll * V * ::L) pR = mid;
		else pL = mid + 1;
		while (nowR - 1 > pR) {
			--nowR;
			work(h, a[nowR], c[nowR]);
		}
		while (nowL + 1 < pL) {
			++nowL;
			work(h, b[nowL], c[nowL]);
		}
	}
	ans[x] = pL;
	copy(f, g, 0, V);
	_rep (i, R, pL + 1) work(f, a[i], c[i]);
	solve(L, pL, qL, x - 1);
	copy(g, f, 0, V);
	rep (i, qL, x) work(f, a[i], c[i]);
	solve(max(pL, x + 1), R, x + 1, qR);
	g = nullptr; h = nullptr;
	delete[] p; delete[] q;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("roguetrader.in", "r", stdin);
	freopen("roguetrader.out", "w", stdout);
#endif
#endif
#ifdef LYOJ
	freopen("roguetrader.in", "r", stdin);
	freopen("roguetrader.out", "w", stdout);
#endif
	ans = (int*) &ans_bk;
	f = (int*) &f_bk;
	scanf("%d %d %d", &n, &V, &L);
	/* n = read(), V = read(), L = read(); */
	update(ans, 1, n, n + 1);
	rep (i, 1, n) scanf("%d %d %d", a + i, b + i, c + i);
	/* rep (i, 1, n) a[i] = read(), b[i] = read(), c[i] = read(); */
	solve(1, n + 1, 1, n);
	ll Sum = -1 * sum(ans, 1, n);
	Sum += 1ll * n * n + n;
	printf("%lld", Sum);
	/* print(Sum); */
	return 0;
}
