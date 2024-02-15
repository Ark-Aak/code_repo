#include <bits/stdc++.h>

#define int __int128

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
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

const int MOD = 998244353;

struct Matrix {
	int a[6][6];
	int N, M;
	void clear() {
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				a[i][j] = 0;
			}
		}
	}
	void init() {
		clear();
		for (int i = 1; i <= 4; i++) a[i][i] = 1;
	}
	Matrix operator*(const Matrix &x) {
		Matrix res;
		res.clear();
		for (int i = 1; i <= 4; i++)
			for (int k = 1; k <= 4; k++)
				for (int j = 1; j <= 4; j++) res.a[i][k] = (res.a[i][k] + a[i][j] * x.a[j][k] % MOD) % MOD;
		return res;
	}
};

int qpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = ans * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return ans;
}

Matrix qpow(Matrix x, int y) {
	Matrix ans;
	ans.init();
	while (y) {
		if (y & 1) ans = ans * x;
		x = x * x;
		y >>= 1;
	}
	return ans;
}

Matrix solve(int p, int q, int r, int l, Matrix a, Matrix b) {
	Matrix res;
	res.init();
	if (!l) return res;
	if (p >= q) return solve(p % q, q, r, l, a, qpow(a, p / q) * b);
	int m = (l * p + r) / q;
	if (!m) return qpow(b, l);
	int cnt = l - (q * m - r - 1) / p;
	return qpow(b, (q - r - 1) / p) * a * solve(q, p, (q - r - 1) % p, m - 1, b, a) * qpow(b, cnt);
}

int n, p, k;

signed main() {
	int T = read();
	while (T--) {
		n = read(), k = read(), p = read();
		p = ((1 - p) % MOD + 2 * MOD) % MOD;
		int ans = 0;
		Matrix U, R;
		U.clear(); R.clear();
		U.a[1][1] = 1, U.a[2][2] = p, U.a[3][3] = p, U.a[4][4] = p, U.a[4][3] = p;
		R.a[1][1] = 1; R.a[2][1] = ((p * k % MOD - k + 2 * MOD) + 2 * MOD) % MOD,
		R.a[2][2] = 1, R.a[3][1] = ((n - n * p % MOD + 2 * MOD) + 2 * MOD) % MOD;
		R.a[4][1] = n, R.a[4][2] = 1; R.a[4][4] = 1; R.a[3][3] = 1;
		Matrix z;
		z.clear(); z.a[1][4] = 1; z = z * R; z = z * solve(k, n, 0, n - 1, U, R);
		ans = z.a[1][1];
		ans = ans * qpow(n, MOD - 2) % MOD;
		ans = ans * qpow(((1 - qpow(p, k)) % MOD + 2 * MOD) % MOD, MOD - 2) % MOD;
		print((ans + 2 * MOD) % MOD), putchar('\n');
	}
	return 0;
}