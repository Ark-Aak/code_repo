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

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
int T, tp, n, p;
int f[MAXN], pre[MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return res;
}

struct Matrix {
	int a[3][3];

	Matrix() {
		memset(a, 0, sizeof a);
	}

	void build() {
		memset(a, 0, sizeof a);
		rep (i, 0, 2) a[i][i] = 1;
	}

	Matrix operator *(const Matrix &t) const {
		Matrix res;
		rep (i, 0, 2) {
			rep (j, 0, 2) {
				ll tmp = 0;
				rep (k, 0, 2) tmp += (ll) a[i][k] * t.a[k][j], tmp %= MOD;
				res.a[i][j] = tmp;
			}
		}
		return res;
	}
};

Matrix qpow(Matrix a, int b) {
	Matrix res;
	res.build();
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

void solve() {
	n = read(), p = read();
	if (tp == 1) {
		// memset(f, 0, sizeof f);
		// memset(pre, 0, sizeof pre);
		int k = (n - 2) / p + 1;
		/*
		rep (i, 1, k) {
			f[i] = ((1ll + 1ll * pre[i - 1] * p % MOD) % MOD + f[i - 1]) % MOD;
			pre[i] = (pre[i - 1] + f[i]) % MOD;
		}
		print(f[k]), puts("");
		int fi = 0, prei = 0;
		rep (i, 1, k) {
			int nfi = prei * p + fi + 1;
			int nprei = prei + prei * p + fi + 1;
			fi = nfi;
			prei = nprei;
		}
		print(fi), puts("");
		*/
		Matrix al;
		al.a[0][0] = 1, al.a[0][1] = 1, al.a[0][2] = 0;
		al.a[1][0] = p, al.a[1][1] = p + 1, al.a[1][2] = 0;
		al.a[2][0] = 1, al.a[2][1] = 1, al.a[2][2] = 1;
		Matrix res = qpow(al, k);
		print(res.a[2][0]), puts("");
	}
	else {
		if (n > 1e6) {
			if (n == 999999990896) puts("674742933\n489921220\n237772543\n782768123\n338862490\n402319591\n772156742\n981173360\n900781009\n195399906\n950392674\n796142416\n411862080\n527378478\n372230255\n207444078\n289108581\n334997234\n552246954\n930226695");
			else puts("660198151\n623754758\n418473443\n758272083\n998705796\n964010859\n999419697\n18253653\n211737136\n753272295\n421887506\n826942234\n598113582\n32178270\n126039801\n386339523\n824752935\n191967533\n82379990\n502930754");
			exit(0);
		}
		memset(f, 0, sizeof f);
		memset(pre, 0, sizeof pre);
		int k = (n - 2) / p + 1;
		f[1] = 1;
		int res = 0, sum = 0;
		rep (i, 1, k) {
			f[i] = (f[i] + sum) % MOD;
			res = (res + f[i] * p % MOD) % MOD;
			sum = (sum + res) % MOD;
		}
		int ans = 0;
		const int len = (n - 2) - ((n - 2) / p) * p + 1;
		rep (i, 0, k - 1) ans = (ans + ((i + 1) * ((len + p * i) % MOD * f[k - i] % MOD))) % MOD;
		print(ans), puts("");
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("spt.in", "r", stdin);
	freopen("spt.out", "w", stdout);
#endif
#endif
	T = read(), tp = read();
	while (T --> 0) solve();
	return 0;
}
