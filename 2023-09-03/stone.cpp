#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MOD = 998244353;

ll qpow(ll a, ll b, ll p) {
	ll res = 1;
	a %= p, b %= p;
	while (b) {
		if (b & 1) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}

struct Matrix {
	int a[2][2];

	Matrix() {
		memset(a, 0, sizeof a);
	}

	void build() {
		memset(a, 0, sizeof a);
		rep (i, 0, 1) a[i][i] = 1;
	}

	Matrix operator *(const Matrix &t) const {
		Matrix res;
		rep (i, 0, 1) {
			rep (j, 0, 1) {
				ll tmp = 0;
				rep (k, 0, 1) tmp += (ll) a[i][k] * t.a[k][j];
				res.a[i][j] = tmp % MOD;
			}
		}
		return res;
	}
};

Matrix qpow(Matrix a, ll b) {
	Matrix res;
	res.build();
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

ll fac[10005], inv[10005];
ll n, d, ans;

ll C(ll a, ll b) {
	return a < b ? 0 : (ll) fac[a] * inv[b] % MOD * inv[a - b] % MOD;
}

int main() {
	cin >> n >> d;
	fac[0] = 1;
	rep (i, 1, d) fac[i] = fac[i - 1] * i % MOD;
	inv[d] = qpow(fac[d], MOD - 2, MOD);
	_rep (i, d, 1) inv[i - 1] = inv[i] * i % MOD;
	rep (i, 0, d + 1) {
		Matrix res;
		rep (j, 0, 1) {
			rep (k, 0, 1) {
				ll tmp = i - j - k;
				if (tmp >= 0) res.a[j][k] = C(d - 1, tmp);
			}
		}
		res = qpow(res, n);
		ans += res.a[0][0];
		ans %= MOD;
		ans += res.a[1][1];
		ans %= MOD;
	}
	cout << ans;
	return 0; 
}
