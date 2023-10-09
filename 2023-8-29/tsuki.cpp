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

const ll MOD = 147744151;
ll n, m, P, Q;
ll a[1005][1005], sum[1005][1005];

ll qpow(ll a, ll b, ll p) {
	a %= p, b %= p;
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tsuki.in", "r", stdin);
	freopen("tsuki.out", "w", stdout);
#endif
#endif
	read(n), read(m), read(P);
	rep (i, 1, n) {
		rep (j, 1, m) read(a[i][j]);
	}
	if (n <= 200 && m <= 200) {
		read(Q);
		ll fAns = 0;
		rep (_ind, 1, Q) {
			ll xa, xb, ya, yb;
			read(xa), read(ya);
			read(xb), read(yb);
			ll ans = 1;
			rep (i, xa, xb) {
				rep (j, ya, yb) {
					ans *= a[i][j];
					ans %= P;
				}
			}
			fAns += (ans ^ _ind) % MOD;
			fAns %= MOD;
		}
		cout << fAns;
		return 0;
	}
	else {
		rep (i, 0, n) rep (j, 0, m) sum[i][j] = 1;
		rep (i, 1, n) {
			rep (j, 1, m) {
				sum[i][j] = (sum[i - 1][j] % P * sum[i][j - 1] % P * a[i][j] % P) % P;
				sum[i][j] = (sum[i][j] % P * qpow(sum[i - 1][j - 1], P - 2, P) % P) % P;
			}
		}
		read(Q);
		ll fAns = 0;
		rep (_ind, 1, Q) {
			ll xa, xb, ya, yb;
			read(xa), read(ya);
			read(xb), read(yb);
			ll ans = 1;
			ans = sum[xb][yb];
			ans = (ans * qpow(sum[xa - 1][yb], P - 2, P) % P) % P;
			ans = (ans * qpow(sum[xb][ya - 1], P - 2, P) % P) % P;
			ans *= sum[xa - 1][ya - 1];
			ans %= P;
			fAns += (ans ^ _ind) % MOD;
			fAns %= MOD;
		}
		cout << fAns;
	}
	return 0; 
}
