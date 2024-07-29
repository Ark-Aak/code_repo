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

#define int ll

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

const int MAXN = 2.5e5 + 5;
const int MAXK = 18;
int n, a[MAXN], b[MAXN];
int ans = 0;

void add(vector <int> &a, vector <int> &b, int *val) {
	rep (i, 0, MAXK) {
		int cx = 0, cy = 0;
		for (auto v : a) cx += val[v] >> i & 1;
		for (auto v : b) cy += val[v] >> i & 1;
		ans += (cx * (b.size() - cy) + cy * (a.size() - cx)) << i;
	}
}

void calc(int R, vector <int> &v) {
	if (!v.size()) return;
	if (R < 0) {
		rep (i, 0, MAXK) {
			int c = 0;
			for (auto p : v) c += a[p] >> i & 1;
			ans += (c * (v.size() - c)) << i;
		}
		return;
	}
	vector <int> cat[2][2];
	for (auto p : v) cat[a[p] >> R & 1][b[p] >> R & 1].push_back(p);
	add(cat[0][0], cat[0][1], a);
	add(cat[0][0], cat[1][0], b);
	add(cat[1][1], cat[0][1], b);
	add(cat[1][1], cat[1][0], a);
	for (auto p : cat[1][1]) cat[0][0].push_back(p);
	for (auto p : cat[1][0]) cat[0][1].push_back(p);
	calc(R - 1, cat[0][0]), calc(R - 1, cat[0][1]);
}

signed main() {
	n = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) b[i] = read();
	vector <int> v;
	rep (i, 1, n) v.push_back(i);
	calc(MAXK, v);
	print(ans);
	return 0;
}
