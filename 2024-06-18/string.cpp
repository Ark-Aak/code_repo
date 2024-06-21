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

const int MAXN = 1e5 + 5;
const int MOD = 998244353;

struct Matrix {
	int c[4][4];

	Matrix() { memset(c, 0, sizeof c); }
	Matrix operator*(Matrix &t) {
		Matrix res;
		rep (i, 1, 3) rep (j, 1, 3) rep (k, 1, 3)
			res.c[i][j] = (res.c[i][j] + c[i][k] * t.c[k][j] % MOD) % MOD;
		return res;
	}
};

Matrix d[3];

namespace seg {
	Matrix sum[MAXN << 2];
	int stat[MAXN];

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

	void pushup(int x) { sum[x] = sum[ls(x)] * sum[rs(x)]; }

	void build(int x, int L, int R) {
		if (L == R) return void(sum[x] = d[stat[L]]);
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		pushup(x);
	}

	void update(int x, int L, int R, int p) {
		if (L == R) return void(sum[x] = d[stat[p]]);
		if (p <= mid) update(ls(x), L, mid, p);
		else update(rs(x), mid + 1, R, p);
		pushup(x);
	}
} // namespace seg

using seg::stat;
int n, q;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	d[0].c[1][1] = 1, d[0].c[1][2] = 1, d[0].c[1][3] = 1;
	d[0].c[2][1] = 0, d[0].c[2][2] = 1, d[0].c[2][3] = 0;
	d[0].c[3][1] = 0, d[0].c[3][2] = 0, d[0].c[3][3] = 1;
	d[1].c[1][1] = 1, d[1].c[1][2] = 0, d[1].c[1][3] = 0;
	d[1].c[2][1] = 1, d[1].c[2][2] = 1, d[1].c[2][3] = 1;
	d[1].c[3][1] = 0, d[1].c[3][2] = 0, d[1].c[3][3] = 1;
	d[2].c[1][1] = 1, d[2].c[1][2] = 1, d[2].c[1][3] = 1;
	d[2].c[2][1] = 1, d[2].c[2][2] = 1, d[2].c[2][3] = 1;
	d[2].c[3][1] = 0, d[2].c[3][2] = 0, d[2].c[3][3] = 1;
	string s;
	cin >> n >> q >> s;
	s = ' ' + s;
	rep (i, 1, n) {
		if (isdigit(s[i])) stat[i] = s[i] - '0';
		else stat[i] = 2;
	}
	seg::build(1, 1, n);
	while (q --> 0) {
		int x;
		char c;
		cin >> x >> c;
		if (isdigit(c)) stat[x] = c - '0';
		else stat[x] = 2;
		seg::update(1, 1, n, x);
		Matrix res;
		res.c[3][1] = 1;
		res = seg::sum[1] * res;
		cout << (res.c[1][1] + res.c[2][1]) % MOD << endl;
	}
	return 0;
}
